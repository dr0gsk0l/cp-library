---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://atcoder.github.io/ac-library/production/document_ja/appendix.html\uFF09"
    - https://github.com/atcoder/ac-library)'s
    - https://murashun.jp/article/programming/regular-expression.html
    - https://note.nkmk.me/python-raw-std::string-escape/
    - https://note.nkmk.me/python-re-match-search-findall-etc/
    - https://qiita.com/kzkadc/items/e4fc7bc9c003de1eb6d0
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\n# This code is based on [ac-lirary](https://github.com/atcoder/ac-library)'s\
    \ expander.py.\n\nimport re\nimport sys\nimport argparse\nfrom logging import\
    \ Logger, basicConfig, getLogger\nfrom os import getenv, environ, pathsep, fspath\n\
    from pathlib import Path, PurePath\nfrom typing import List, Set, Optional\nfrom\
    \ subprocess import call\nimport pyperclip\n\nlogger = getLogger(__name__)  #\
    \ type: Logger\n\nRED = '\\033[91m'\nBLUE = '\\033[94m'\nGREEN = '\\033[92m'\n\
    END = '\\033[0m'\n\n# __\uFF08\u30A2\u30F3\u30C0\u30FC\u30D0\u30FC\u4E8C\u3064\
    \uFF09 \u3067\u59CB\u307E\u308B\u3082\u306E\u306F private\nclass Expander:\n \
    \   # re \u306F\u6B63\u898F\u8868\u73FE\u3092\u4F7F\u3046\u305F\u3081\u306E\u30C4\
    \u30FC\u30EB https://note.nkmk.me/python-re-match-search-findall-etc/\n    # library_include\
    \ \u306B\u4EE5\u4E0B\u306E\u6B63\u898F\u8868\u73FE\u3092\u4EE3\u5165\u3057\u3066\
    \u3044\u308B\n    # r'' \u306F raw \u6587\u5B57\u5217 \u30A8\u30B9\u30B1\u30FC\
    \u30D7\u30B7\u30FC\u30B1\u30F3\u30B9\u3092\u3057\u306A\u304F\u3066\u826F\u304F\
    \u306A\u308B https://note.nkmk.me/python-raw-std::string-escape/\n    # acl \u3068\
    \u81EA\u5206\u306E\u3092\u5206\u3051\u3066\u3044\u308B\u306E\u306F\u3001acl \u5185\
    \u306E <algorithm> \u306A\u3069\u3092\u63A2\u3055\u306A\u3044\u3088\u3046\u306B\
    \u3059\u308B\u305F\u3081\n    \n    \n    # \u6B63\u898F\u8868\u73FE\u306E\u89E3\
    \u8AAC https://murashun.jp/article/programming/regular-expression.html\n    #\
    \ \\s : \u30B9\u30DA\u30FC\u30B9\n    # [~] : ~ \u5185\u306E\u3044\u305A\u308C\
    \u304B1\u6587\u5B57\n    # (~) : ~ \u3092\u4E00\u3064\u306E\u30B0\u30EB\u30FC\u30D7\
    \u3068\u898B\u505A\u3059 \u3042\u307E\u308A\u6C17\u306B\u3057\u306A\u304F\u3066\
    \u826F\u3044\n    # a-z, A-Z : \u5C0F\u6587\u5B57,\u5927\u6587\u5B57\u5168\u3066\
    \n    # * : \u76F4\u524D\u306E\u6587\u5B57 0 \u56DE\u4EE5\u4E0A \u6700\u9577\u4E00\
    \u81F4\n    # | : OR \u524D\u5F8C\u306E\u3044\u305A\u308C\u304B\u3068\u30DE\u30C3\
    \u30C1 (|.cpp) \u306F (\u2205 OR .cpp)\n\n    # __init__ \u306F\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF C++ \u3067\u8A00\u3048\u3070 Expander() \u3068\u540C\u3058\
    \u610F\u5473\n    # self \u306F\u4ECA\u3044\u308B class(Expander) \u81EA\u4F53\
    \u306E\u3053\u3068\u3092\u6307\u3057\u3001\u5916\u90E8\u304B\u3089\u3053\u306E\
    \u95A2\u6570\u3092\u547C\u3076\u5834\u5408\u306B\u306F\u5F15\u6570\u306B\u66F8\
    \u304B\u306A\u304F\u3066 ok\n    # Expander \u306E\u5909\u6570 lib_paths \u306B\
    \u5F15\u6570\u306E lib_paths \u3092\u4EE3\u5165 List[Path] \u306F\u578B\u3092\u660E\
    \u793A\u7684\u306B\u66F8\u3044\u3066\u308B\n    # Path \u306F pathlib \u304B\u3089\
    \ import \u3057\u305F\u578B\n    # lib_paths \u306F list \u306A\u306E\u3067\u3001\
    \u8907\u6570\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u6E21\u305B\u308B\n   \
    \ def __init__(self, lib_paths: List[Path], acl_compile:bool, replace_endl:bool):\n\
    \        self.lib_paths = lib_paths\n        self.replace_endl = replace_endl\n\
    \        acl_pattern = 'atcoder/[a-z_]*(|.hpp)'\n        drog_pattern = '[/\\\
    w]*.cpp'\n        if acl_compile:\n            self.__library_include_checker\
    \ = re.compile(r'#include\\s*[\"<]({}|{})[\">]\\s*'.format(acl_pattern,drog_pattern))\n\
    \        else:\n            self.__library_include_checker = re.compile(r'#include\\\
    s*[\"<]({})[\">]\\s*'.format(drog_pattern))\n\n    # library \u306E\u540D\u524D\
    \u3092\u6E21\u3057\u3066\u3001\uFF08\u898B\u3064\u304B\u308C\u3070\uFF09\u305D\
    \u3053\u3078\u306E\u30D1\u30B9\u3092\u8FD4\u3059\n    def __find_library_path(self,\
    \ library_file_name: str) -> Path:\n        for lib_path in self.lib_paths:\n\
    \            path = lib_path / library_file_name\n            if path.exists():\n\
    \                return path\n        logger.error(RED + 'cannot find: {}'.format(library_file_name)\
    \ + END)\n        raise FileNotFoundError()\n    \n    # include \u3057\u305F\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u4E00\u89A7\n    __included = set()  # type: Set[Path]\n\
    \n    # acl \u306E include_guard \n    # drogskol library \u306F pragma once \u3092\
    \u4F7F\u3063\u3066\u3044\u308B\u304C\u3001acl \u306E expand \u3082\u3057\u305F\
    \u3044\u70BA\u6B8B\u3057\u3066\u308B\n    __include_guard = re.compile(r'#.*ATCODER_[A-Z_]*_HPP')\n\
    \n    # \u305D\u306E\u884C\u304C\u7121\u8996\u3057\u3066\u3044\u3044\u884C\u304B\
    \u3069\u3046\u304B\n    # c++ \u3067 *this \u3068\u66F8\u304F\u90E8\u5206\u3067\
    \u4EE3\u308F\u308A\u306B\u5177\u4F53\u7684\u306A\u5909\u6570\u540D\u3092\u4F7F\
    \u3063\u3066\u308B\u611F\u3058\u3067\u3001self \u306A\u306E\u306F\u305F\u3060\u306E\
    \u6163\u4F8B\n    def __is_ignored_line(self, line) -> bool:\n        if self.__include_guard.match(line):\n\
    \            return True\n        if line.strip() == \"#pragma once\":\n     \
    \       return True\n        if line.strip().startswith('//'):\n            return\
    \ True\n        return False\n\n    # library \u306E path \u3092\u6E21\u3057\u3066\
    \u5C55\u958B\u3059\u308B\u6587\u5B57\u5217\uFF08\u30E9\u30A4\u30D6\u30E9\u30EA\
    \u306E\u4E2D\u8EAB\uFF09\u3092\u8FD4\u3059\n    def __expand_library(self, library_file_path:\
    \ Path) -> List[str]:\n        # \u65E2\u306B include \u3055\u308C\u3066\u3044\
    \u308B\u304B\u3092 check\n        if library_file_path in self.__included:\n \
    \           logger.info('already included: {}'.format(library_file_path.name))\n\
    \            return []\n        self.__included.add(library_file_path)\n     \
    \   logger.info(BLUE + 'include: {}'.format(library_file_path.name) + END)\n\n\
    \        library_source = open(str(library_file_path)).read()\n\n        result\
    \ = []  # type: List[str]\n        for line in library_source.splitlines():\n\
    \            if self.__is_ignored_line(line):\n                continue\n\n  \
    \          # \u5C55\u958B\u3057\u305F\u6587\u5B57\u5217\u306E\u4E2D\u306B\u3055\
    \u3089\u306B include \u304C\u3042\u308B\u5834\u5408\n            m = self.__library_include_checker.match(line)\n\
    \            if m:\n                name = m.group(1) # match \u3057\u305F\u6587\
    \u5B57\u5217\n                result.extend(self.__expand_library(self.__find_library_path(name)))\n\
    \                continue\n\n            result.append(line)\n        return result\n\
    \    \n    # \u5916\u90E8\u304B\u3089\u306F\u3053\u308C\u304C\u4E00\u56DE\u547C\
    \u3073\u51FA\u3055\u308C\u308B\u3060\u3051\n    # source \u306F\u5177\u4F53\u7684\
    \u306A\u30D7\u30ED\u30B0\u30E9\u30E0\uFF08b.cpp \u3068\u304B\uFF09\u306E\u4E2D\
    \u8EAB\n    # \u5C55\u958B\u3055\u308C\u305F\u30B3\u30FC\u30C9\uFF08combined.cpp\uFF09\
    \u3092\u8FD4\u3059\n    def expand(self, source: str) -> str:\n        self.__included\
    \ = set()\n        result = []  # type: List[str]\n        for line in source.splitlines():\n\
    \            m = self.__library_include_checker.match(line)\n            if m:\n\
    \                library_path = self.__find_library_path(m.group(1))\n       \
    \         result.extend(self.__expand_library(library_path))\n               \
    \ continue\n\n            if self.replace_endl:\n                line = line.replace('endl',\"\
    '\\\\n'\")\n            result.append(line)\n        return '\\n'.join(result)\n\
    \n\nif __name__ == \"__main__\":\n    # logger \u306E\u8A2D\u5B9A\n    basicConfig(\n\
    \        format=\"[%(levelname)s] %(message)s\",\n        level=getenv('LOG_LEVEL',\
    \ 'INFO'),\n    )\n\n    # \u30B3\u30DE\u30F3\u30C9\u30E9\u30A4\u30F3\u5F15\u6570\
    \u3092\u8A2D\u5B9A\u3059\u308B\u305F\u3081\u306E\u3082\u306E https://qiita.com/kzkadc/items/e4fc7bc9c003de1eb6d0\n\
    \    # description \u306F\u30B3\u30E1\u30F3\u30C8\u307F\u305F\u3044\u306A\u3082\
    \u306E\u3000\u5225\u306B\u66F8\u304B\u306A\u304F\u3066\u3082\u826F\u3044\n   \
    \ parser = argparse.ArgumentParser(description='Expander')\n\n    # add_argument('arg1')\
    \ \u3068\u66F8\u304F\u3068\u3001\"python expander.py tomato\" \u3067\u5B9F\u884C\
    \u3059\u308C\u3070 arg1 \u306B tomato \u304C\u4EE3\u5165\u3055\u308C\u308B\n \
    \   # help \u306F\u5F15\u6570\u306E\u8AAC\u660E\u3067\u30B3\u30E1\u30F3\u30C8\u307F\
    \u305F\u3044\u306A\u3082\u306E\u3000\u5225\u306B\u66F8\u304B\u306A\u304F\u3066\
    \u3082\u826F\u3044 \"python expander.py --help\" \u3092\u3059\u308B\u3068\u5404\
    \u5909\u6570\u306E help \u304C\u8868\u793A\u3055\u308C\u308B\n    # '--arg2' \u3068\
    \u66F8\u3044\u305F\u5834\u5408\u306F\u30AA\u30D7\u30B7\u30E7\u30F3\u5F15\u6570\
    \u306B\u306A\u308B \"--arg2 sarusa\" \u3092\u4ED8\u3051\u308C\u3070 arg2 \u306B\
    \ sarusa \u304C\u4EE3\u5165\u3055\u308C\u308B\n    # \u3053\u306E\u6642 '-a2'\
    \ \u3068\u4E00\u7DD2\u306B\u66F8\u3051\u3070 \"-a2 sarusa\" \u3067\u3082\u826F\
    \u304F\u306A\u308B\uFF08\u7701\u7565\u5F62\uFF09\n    # action='store_true' \u306F\
    \u5F15\u6570\u3092\u53D6\u3089\u305A\u3001\u5B9F\u884C\u6642\u306B\u305D\u308C\
    \u306E --arg \u304C\u547C\u3070\u308C\u3066\u3044\u305F\u3089 true \u304C\u4EE3\
    \u5165\u3055\u308C\u308B\n    # \u4E0A\u306E qiita \u3092\u8AAD\u3080\u3068 action\
    \ \u3084 help \u4EE5\u5916\u306B\u3082\u8272\u3005\u3042\u3063\u3066\u697D\u3057\
    \u3044\n    parser.add_argument('source', nargs='?', default='b.cpp', help='Source\
    \ File')\n    parser.add_argument('--lib', nargs='*', help='Path to Library')\n\
    \    parser.add_argument('--pbcopy', '-cp', action='store_true', help='output\
    \ to pbcopy')\n    parser.add_argument('--acl', action='store_true', help='expand\
    \ acl')\n    parser.add_argument('--endl', action='store_false', help='not replace\
    \ std::endl')\n    opts = parser.parse_args()\n\n    print(\"[INFO] \" + GREEN\
    \ + \"expand library\" + END)\n\n    lib_paths = []\n    if opts.lib:\n      \
    \  for lib in opts.lib:\n            lib_paths.append(Path(lib))\n\n    # \u74B0\
    \u5883\u5909\u6570\uFF08environ\uFF09\u306E 'CPLUS_INCLUDE_PATH' \u3067\u81EA\u5206\
    \u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u30D1\u30B9\u3092\u6307\u5B9A\u3057\
    \u305F\u3044\u6642\u306B\u4F7F\u3046\u3082\u306E\u3060\u3068\u601D\u3046\uFF08\
    https://atcoder.github.io/ac-library/production/document_ja/appendix.html\uFF09\
    \n    if 'CPLUS_INCLUDE_PATH' in environ:\n        lib_paths.extend(std(Path,\
    \ filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))\n    \n    # \u30AB\
    \u30EC\u30F3\u30C8\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u3092 lib_paths \u306B\u8FFD\
    \u52A0\n    lib_paths.append(Path.cwd())\n    # Expander \u306E\u69CB\u7BC9\n\
    \    expander = Expander(lib_paths,opts.acl,opts.endl)\n    # \u30B3\u30DE\u30F3\
    \u30C9\u30E9\u30A4\u30F3\u5F15\u6570\u304B\u3089 source \u3092\u53D6\u308A\u51FA\
    \u3059\n    source = open(opts.source).read()\n    # combined.cpp \u306E\u4F5C\
    \u6210\n    output = expander.expand(source)\n\n    # pbcopy \u304C\u6307\u5B9A\
    \u3055\u308C\u3066\u3044\u308C\u3070\u30AF\u30EA\u30C3\u30D7\u30DC\u30FC\u30C9\
    \u306B\u51FA\u529B\n    if opts.pbcopy:\n        pyperclip.copy(output)\n    else:\n\
    \        with open('combined.cpp', 'w') as f:\n            f.write(output)"
  dependsOn: []
  isVerificationFile: false
  path: library/local/expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/expander.py
layout: document
redirect_from:
- /library/library/local/expander.py
- /library/library/local/expander.py.html
title: library/local/expander.py
---
