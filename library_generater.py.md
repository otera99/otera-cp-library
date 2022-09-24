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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\nimport re\nfrom logging import Logger, basicConfig,\
    \ getLogger\nfrom os import getenv, path, listdir\nfrom shutil import copy\n\n\
    FILE_PATH = 'library'\nOTERA_PATH = 'otera'\n\nlogger = getLogger(__name__)  #\
    \ type: Logger\n\nclass Generator:\n    library_include = re.compile(\n      \
    \  r'#include\\s*[\"<](library/[a-z_/A-Z]*(|.hpp))[\">]\\s*')\n\n    def __init__(self):\n\
    \        pass\n\n    def extract_library_name(self, lib_include):\n        ret\
    \ = \"\"\n        for i in range(len(lib_include)):\n            if lib_include[i]\
    \ == '/':\n                ret = \"\"\n            elif lib_include[i] == '.':\n\
    \                return ret\n            else:\n                ret += lib_include[i]\n\
    \n    def generate(self, lib_path, file_name, otera_path, otera_all_file):\n \
    \       print(\"[INFO] generate: \" + file_name)\n        # copy(lib_path, otera_path\
    \ + '/' + file_name)\n        otera_file = open(otera_path + '/' + file_name,\
    \ \"w\")\n        lib_file = open(lib_path).read()\n        for line in lib_file.splitlines():\n\
    \            if self.library_include.match(line):\n                otera_file.write(\"\
    #include<otera/\" + self.extract_library_name(line) + \">\")\n               \
    \ otera_file.write('\\n')\n                continue\n            otera_file.write(line)\n\
    \            otera_file.write('\\n')\n        otera_file.close()\n        print(\"\
    [INFO] generate: \" + file_name[:-4])\n        new_file_path = otera_path + '/'\
    \ + file_name[:-4]\n        new_file = open(new_file_path, 'w')\n        file_include\
    \ = \"#include <\" + otera_path + '/' + file_name + '>'\n        new_file.write(file_include)\n\
    \        otera_all_file.write(file_include)\n        otera_all_file.write('\\\
    n')\n        new_file.close()\n\n    def file_check(self, lib_path, file_name,\
    \ otera_all_file):\n        if path.isdir(lib_path):\n            files = listdir(lib_path)\n\
    \            for file in files:\n                self.file_check(lib_path + '/'\
    \ + file, file, otera_all_file)\n\n        else:\n            if lib_path[-4:]\
    \ == '.hpp':\n                self.generate(lib_path, file_name, OTERA_PATH, otera_all_file)\n\
    \nif __name__ == \"__main__\":\n    basicConfig(\n        format=\"%(asctime)s\
    \ [%(levelname)s] %(message)s\",\n        datefmt=\"%H:%M:%S\",\n        level=getenv('LOG_LEVEL',\
    \ 'INFO'),\n    )\n    otera_all_file = open(OTERA_PATH + \"/all\", \"w\")\n \
    \   generator = Generator()\n    generator.file_check(FILE_PATH, '', otera_all_file)\n\
    \    print(\"[INFO] generate: all\")\n    otera_all_file.close()"
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