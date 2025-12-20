# コーディング規約

- `.clang-format` を常に適用し、IndentWidth=4 を守ります。`REP` / `RREP` など自前マクロもフォーマッタに登録されているため崩れません。
- ファイル名、構造体名、名前空間名は UpperCamelCase。ディレクトリや自由関数は小文字またはスネークケースに統一します。
- 実在型を指すテンプレートパラメータは `template<class GRAPH>` のように全大文字。概念名 (`Monoid`, `Info` など) は PascalCase のまま使います。
- 単体で動くテストコードは `test/README.md` に記載のテンプレート（`#define PROBLEM ""` と `<bits/stdc++.h>`）から開始し、`std::ios::sync_with_stdio(false);` など基本設定も従ってください。
- ファイル先頭で `#include <bits/stdc++.h>` を使い、必要に応じて `#include "library/....hpp"` で自作ヘッダを読み込みます。***
