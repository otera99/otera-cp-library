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
    - https://github.com/atcoder/ac-library)
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# this code is mainly writed by AtCoder Library (https://github.com/atcoder/ac-library)\n\
    #!/usr/bin/env python3\n\nimport re\nimport sys\nimport argparse\nfrom logging\
    \ import Logger, basicConfig, getLogger\nfrom os import getenv, environ, pathsep\n\
    from pathlib import Path\nfrom typing import List, Set, Optional\n\n\nlogger =\
    \ getLogger(__name__)  # type: Logger\n\n\nclass Expander:\n    library_include\
    \ = re.compile(\n        r'#include\\s*[\"<](library/[a-z_/A-Z]*(|.hpp))[\">]\\\
    s*')\n\n    include_guard = re.compile(r'#.*LIBRARY_[A-Z_]*_HPP')\n\n    def is_ignored_line(self,\
    \ line) -> bool:\n        if self.include_guard.match(line):\n            return\
    \ True\n        if line.strip() == \"#pragma once\":\n            return True\n\
    \        if line.strip().startswith('//'):\n            return True\n        return\
    \ False\n\n    def __init__(self, lib_paths: List[Path]):\n        self.lib_paths\
    \ = lib_paths\n\n    included = set()  # type: Set[Path]\n\n    def find_otera(self,\
    \ otera_name: str) -> Path:\n        for lib_path in self.lib_paths:\n       \
    \     path = lib_path / otera_name\n            if path.exists():\n          \
    \      return path\n        logger.error('cannot find: {}'.format(otera_name))\n\
    \        raise FileNotFoundError()\n\n    def expand_otera(self, otera_file_path:\
    \ Path) -> List[str]:\n        if otera_file_path in self.included:\n        \
    \    logger.info('already included: {}'.format(otera_file_path.name))\n      \
    \      return []\n        self.included.add(otera_file_path)\n        logger.info('include:\
    \ {}'.format(otera_file_path.name))\n\n        otera_source = open(str(otera_file_path)).read()\n\
    \n        result = []  # type: List[str]\n        for line in otera_source.splitlines():\n\
    \            if self.is_ignored_line(line):\n                continue\n\n    \
    \        m = self.library_include.match(line)\n            if m:\n           \
    \     name = m.group(1)\n                result.extend(self.expand_otera(self.find_otera(name)))\n\
    \                continue\n\n            result.append(line)\n        return result\n\
    \n    def expand(self, source: str) -> str:\n        self.included = set()\n \
    \       result = []  # type: List[str]\n        for line in source.splitlines():\n\
    \            m = self.library_include.match(line)\n            if m:\n       \
    \         otera_path = self.find_otera(m.group(1))\n                result.extend(self.expand_otera(otera_path))\n\
    \                continue\n\n            result.append(line)\n        return '\\\
    n'.join(result)\n\n\nif __name__ == \"__main__\":\n    basicConfig(\n        format=\"\
    %(asctime)s [%(levelname)s] %(message)s\",\n        datefmt=\"%H:%M:%S\",\n  \
    \      level=getenv('LOG_LEVEL', 'INFO'),\n    )\n    parser = argparse.ArgumentParser(description='Expander')\n\
    \    parser.add_argument('source', help='Source File')\n    parser.add_argument('-c',\
    \ '--console',\n                        action='store_true', help='Print to Console')\n\
    \    parser.add_argument('--lib', help='Path to Otera Library')\n    opts = parser.parse_args()\n\
    \n    lib_paths = []\n    if opts.lib:\n        lib_paths.append(Path(opts.lib))\n\
    \    if 'CPLUS_INCLUDE_PATH' in environ:\n        lib_paths.extend(\n        \
    \    map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))\n\
    \    lib_paths.append(Path.cwd())\n    expander = Expander(lib_paths)\n    source\
    \ = open(opts.source).read()\n    output = expander.expand(source)\n\n    if opts.console:\n\
    \        print(output)\n    else:\n        with open('combined.cpp', 'w') as f:\n\
    \            f.write(output)\n"
  dependsOn: []
  isVerificationFile: false
  path: expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expander.py
layout: document
redirect_from:
- /library/expander.py
- /library/expander.py.html
title: expander.py
---
