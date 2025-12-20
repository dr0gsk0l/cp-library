# ビルド・検証コマンド

- `.verify-helper/config` に従い `g++ -std=gnu++23 -Wall -O2 -I ac-library -include build/pch/stdc++.hpp` でコンパイルされます。検証前に `bash scripts/setup-toolchain.sh` で PCH を必ず作ってください。
- ローカルでは `bash scripts/setup-toolchain.sh` → `bash scripts/ce-check.sh` の順に走らせたあと、`bash scripts/oj-verify.sh all --timeout 100000` で検証します（スクリプトが自動で `--jobs` と ccache を設定します）。
- CE チェックで失敗したファイルのログは `build/ce-check/*.log` に残り、CI では artifacts (`ce-check-logs`) として自動保存されるので詳細をここから確認してください。
- 個別テストは `oj-verify run test/library-checker/Polynomial/Convolution.test.cpp` のように `oj-verify run <path>` で実行します。開発中はここで素早く回すのが基本です。
- 変更をコミットする前に `oj-verify all --timeout 100000 --jobs <コア数>` を実行し、GitHub Actions（実機の CPU 数と 8 の小さい方）と近い条件で全テストが通ることを確認します。`scripts/oj-verify.sh` は `--jobs` を付け忘れた場合に自動で最適値を補います。
- GitHub Pages 用の資料やリファレンスを更新したら `oj-verify docs` を走らせ、`docs/` と公開サイトに差分がないことを確かめてからプッシュします。
- `ac-library/` などサブモジュールを更新した場合は `git submodule update --remote` を実行し、CI とローカルの環境差を無くします。***
