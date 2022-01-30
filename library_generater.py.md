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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from logging import Logger, basicConfig, getLogger\nfrom os import getenv,\
    \ path, listdir\nfrom shutil import copy\n\nFAILE_PATH = 'library'\nOTERA_PATH\
    \ = 'otera'\n\nlogger = getLogger(__name__)  # type: Logger\n\nclass Generator:\n\
    \    def __init__(self):\n        pass\n\n    def generate(self, lib_path, file_name,\
    \ otera_path):\n        print(\"generate: \" + file_name)\n        copy(lib_path,\
    \ otera_path + '/' + file_name)\n\n    def file_check(self, lib_path, file_name):\n\
    \        if path.isdir(lib_path):\n            files = listdir(lib_path)\n   \
    \         for file in files:\n                self.file_check(lib_path + '/' +\
    \ file, file)\n\n        else:\n            if lib_path[-4:] == '.hpp':\n    \
    \            self.generate(lib_path, file_name, OTERA_PATH)\n\nif __name__ ==\
    \ \"__main__\":\n    basicConfig(\n        format=\"%(asctime)s [%(levelname)s]\
    \ %(message)s\",\n        datefmt=\"%H:%M:%S\",\n        level=getenv('LOG_LEVEL',\
    \ 'INFO'),\n    )\n    generator = Generator()\n    generator.file_check(FAILE_PATH,\
    \ '')"
  dependsOn: []
  isVerificationFile: false
  path: library_generater.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library_generater.py
layout: document
redirect_from:
- /library/library_generater.py
- /library/library_generater.py.html
title: library_generater.py
---
