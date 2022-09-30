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
    - https://github.com/atcoder/ac-library)'s
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\n#!/usr/bin/env python3\n\n# This code is based\
    \ on [ac-lirary](https://github.com/atcoder/ac-library)'s expander.py.\n\nimport\
    \ re\nimport sys\nimport argparse\nfrom os import getenv, environ, pathsep, fspath\n\
    from pathlib import Path, PurePath\n\nif __name__ == \"__main__\":\n    parser\
    \ = argparse.ArgumentParser(description='Expander')\n    parser.add_argument('source',\
    \ help='Source File')\n    parser.add_argument('--lib', help='Path to Otera Library')\n\
    \    opts = parser.parse_args()\n    \n    lib_paths = []\n    if opts.lib:\n\
    \        lib_paths.append(Path(opts.lib))\n    else:\n        print(\"[ERROR]\
    \ CAN NOT FIND LIB_PATH\")\n        exit(0)\n    \n    modify_file = \"modify.cpp\"\
    \n    modify_writer = open(modify_file, \"w\")\n    target_reader = open(opts.source).read()\n\
    \    for line in target_reader.splitlines():\n        if line == \"#include<bits/stdc++.h>\"\
    :\n            for line2 in open(opts.lib+\"/modify_template.cpp\").read().splitlines():\n\
    \                modify_writer.write(line2)\n                modify_writer.write(\"\
    \\n\")\n        else:\n            modify_writer.write(line)\n            modify_writer.write(\"\
    \\n\")\n            \n    modify_writer.close()\n    \n    print(\"[INFO] generate\
    \ modify.cpp\")\n    \n\n    \n"
  dependsOn: []
  isVerificationFile: false
  path: modify.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modify.py
layout: document
redirect_from:
- /library/modify.py
- /library/modify.py.html
title: modify.py
---
