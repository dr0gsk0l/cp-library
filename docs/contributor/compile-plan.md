# コンパイル高速化 計画書

## 目的
Mac（Apple Silicon）環境で `*.test.cpp` を `g++` でコンパイルする際、`<bits/stdc++.h>` の解析に時間が掛かり 1 本あたり数秒を要している。CI 前の CE チェックを現実的な時間で回すため、ローカル環境のビルド時間を 1/3 程度に短縮する。

## 現状整理
- 利用コンパイラはシステム付属の `clang++` (Xcode) と `g++-14`（Homebrew）が混在。`g++` は古い `g++-13` へのシンボリックリンク欠如で失敗するケースあり。
- `bits/stdc++.h` からのヘッダ展開を毎回ゼロから実行しており、プリコンパイル済みヘッダ（PCH）や `ccache` が無い。
- `scripts/ce-check.sh` が 100 近い `.test.cpp` を直列に `-O2` 付きでコンパイルしているため、警告抑制やヘッダメモ化が効いていない。

## 改善方針
1. **コンパイラ整理**
   - Homebrew 版 `gcc` (`g++-14` 以降) を導入し、`/opt/homebrew/opt/gcc/bin/g++-14` を `g++` として利用できるようにする（`ln -sf g++-14 /opt/homebrew/bin/g++` など）。
   - `.verify-helper/config` や `scripts/ce-check.sh` の `CXX` 既定値は引き続き GNU `g++` 系で統一し、競プロ本番環境と一致させる。
2. **ビルドキャッシュ**
   - `brew install ccache` を行い、`clang++`/`g++` のラッパとして設定。
   - `scripts/ce-check.sh` と CI に `export PATH="/opt/homebrew/opt/ccache/libexec:$PATH"` を追加し、ヘッダキャッシュを再利用。
3. **プリコンパイルヘッダ(PCH)**
   - `<bits/stdc++.h>` を `pch/bits/stdc++.h.gch` として `g++ -std=gnu++23 -O0` で生成。
   - CE チェックでは `-include bits/stdc++.h` + `-Winvalid-pch` を利用し、PCH ミスマッチ時に自動再生成するスクリプトを追加。
4. **フラグ最適化**
   - CE チェックでは `-O0 -fsyntax-only` に変更し、警告は `-Wno-unused-result` 等必要最小限に絞る。
   - 大量の警告が出る既存コードには `#pragma` でローカル抑制し、ビルドログを短縮。
5. **並列化**
   - `scripts/ce-check.sh` を `xargs -P "$(sysctl -n hw.logicalcpu)"` で並列化し、1 ジョブあたりのコンパイルを分散。
   - 失敗時のログを保つため、`mktemp` で個別ログを残し、エラーがあれば集約して出力。

## 実施ステップ
1. `brew install llvm ccache` を実行し、新バージョンの `clang++` とキャッシュを準備。
2. `scripts/setup-toolchain.sh`（新規）を作成し、PCH の生成と PATH 設定を自動化。
3. `scripts/ce-check.sh` を更新し、(a) PCH の自動生成チェック、(b) `xargs` 並列実行、(c) `-O0` への切り替えを実装。
4. `.github/workflows/verify.yml` でも同スクリプトを利用し、CI 上でも PCH + ccache を使うように調整。
5. ローカルで `time bash scripts/ce-check.sh` を回し、1 本あたりの平均時間を計測。目標値（1 テスト 0.5 秒以下）に届かない場合は追加対策（`llvm-include-what-you-use` や `pch` 位置見直し）を検討。

## 成功判定
- ローカル CE チェックが 100 本の `.test.cpp` で 1 分以内に完走。
- CI の「Compile tests」ステップが 5 分以内で完了し、`oj-verify all` への影響がない。
- PCH や ccache のメンテナンス手順が `docs/contributor/build-test.md` に追記され、他開発者も同じセットアップで再現可能。
