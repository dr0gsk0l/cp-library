---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\nimport argparse\nfrom subprocess import run, PIPE\n\
    import os\n\nRED = '\\033[91m'\nBLUE = '\\033[94m'\nGREEN = '\\033[92m'\nEND =\
    \ '\\033[0m'\n\ndef add(input_txt, correct_txt):\n  n=1\n  while(os.path.exists(\"\
    test/x-sample-{}.in\".format(n))):\n    n+=1\n  with open(\"test/x-sample-{}.in\"\
    .format(n), mode='w') as f:\n    f.write(input_txt)\n  with open(\"test/x-sample-{}.out\"\
    .format(n), mode='w') as f:\n    f.write(correct_txt)\n  print(GREEN + \"ADD x-sample-{}\"\
    .format(n) + END)\n\nif __name__== \"__main__\":\n  parser = argparse.ArgumentParser()\n\
    \  parser.add_argument(\"--number\", '-n', type=int, default='100000', metavar='100',\
    \ help='\u8A66\u884C\u56DE\u6570')\n  parser.add_argument(\"--diff\", \"-d\",\
    \ type=float, metavar='0.1', help=\"\u7D76\u5BFE\u8AA4\u5DEE\")\n\n  opts = parser.parse_args()\n\
    \n  for i in range(opts.number):\n    input_result = run([\"./make_random.out\"\
    ], stdout=PIPE, text=True)\n    if input_result.returncode != 0:\n      print(RED\
    \ + \"input \u3092\u4F5C\u308B\u306E\u306B\u5931\u6557\" + END)\n      exit()\n\
    \    input_txt = input_result.stdout\n\n    tle_result = run(\"./tle.out\", input=input_txt,\
    \ stdout=PIPE, text=True)\n    if tle_result.returncode != 0:\n      print(BLUE\
    \ + \"INPUT:\" + END)\n      print(input_txt)\n      print(RED + \"\u611A\u76F4\
    \u89E3\u304C RE\" +END)\n      exit()\n    correct_txt = tle_result.stdout\n\n\
    \    solve_result = run(\"./a.out\", input=input_txt, stdout=PIPE, text=True)\n\
    \    if solve_result.returncode != 0:\n      print(BLUE + \"INPUT:\" + END)\n\
    \      print(input_txt)\n      print(BLUE + \"CORRECT:\" +END)\n      print(correct_txt)\n\
    \      print(RED + \"YOUR CODE is RE\" + END)\n      add(input_txt,correct_txt)\n\
    \      exit()\n    output_txt = solve_result.stdout\n\n    if (opts.diff and abs(correct_txt-output_txt)>diff)\
    \ or (not opts.diff and correct_txt != output_txt):\n      print(BLUE + \"INPUT:\"\
    \ + END)\n      print(input_txt)\n      print(BLUE + \"CORRECT:\" +END)\n    \
    \  print(correct_txt)\n      print(BLUE + \"WRONG\" + END)\n      print(output_txt)\n\
    \      add(input_txt,correct_txt)\n      exit()\n    \n    if (i&(i+1)) == 0:\n\
    \      print(GREEN + \"{}\u56DE\u306E\u63A2\u7D22\".format(i+1) + END)\n  print(GREEN\
    \ + \"{}\u56DE\u306E\u63A2\u7D22\".format(opts.number) + END)"
  dependsOn: []
  isVerificationFile: false
  path: library/local/hack.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/hack.py
layout: document
redirect_from:
- /library/library/local/hack.py
- /library/library/local/hack.py.html
title: library/local/hack.py
---
