# プロジェクト構成

- コア実装は `library/` にモジュール別で配置します。ディレクトリは小文字またはスネークケース、ファイル名と型名は UpperCamelCase で揃えると検索しやすくなります（例: `datastructure/FenwickTree.hpp`）。
- `ac-library/` は AtCoder 公式のサブモジュールです。`git submodule update --remote` で常に最新へ追従し、検証や CI 前に齟齬がないか確認してください。
- `docs/` は `library/` と同じ階層構造で記事・証明を配置し、GitHub Pages の生成元にもなります。記事を追加するときは対応する `library/` のパスと同じ構成にしてください。
- テストは `test/<contest>/<Problem>.test.cpp` 形式（例: `test/library-checker/Polynomial/Convolution.test.cpp`）。AtCoder、AOJ、library-checker、yukicoder など問題ソースごとにディレクトリを分けます。
- 追加の生成器や補助スクリプトは最も関連の深いディレクトリに置き、README で利用方法を簡潔に説明します。***
