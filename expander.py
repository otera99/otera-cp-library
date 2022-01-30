# this code is mainly writed by AtCoder Library (https://github.com/atcoder/ac-library).
#!/usr/bin/env python3

import re
import sys
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ, pathsep, fspath
from pathlib import Path, PurePath
from typing import List, Set, Optional
from subprocess import call

logger = getLogger(__name__)  # type: Logger


class Expander:
    library_include = re.compile(
        r'#include\s*["<](otera/[a-z_/A-Z]*(|.hpp))[">]\s*')

    include_guard = re.compile(r'#.*LIBRARY_[A-Z_]*_HPP')

    def is_ignored_line(self, line) -> bool:
        if self.include_guard.match(line):
            return True
        if line.strip() == "#pragma once":
            return True
        if line.strip().startswith('//'):
            return True
        return False

    def __init__(self, lib_paths: List[Path]):
        self.lib_paths = lib_paths

    included = set()  # type: Set[Path]

    def find_otera(self, otera_name: str) -> Path:
        for lib_path in self.lib_paths:
            path = lib_path / otera_name
            if path.exists():
                return path
        logger.error('cannot find: {}'.format(otera_name))
        raise FileNotFoundError()

    def expand_otera(self, otera_file_path: Path) -> List[str]:
        if otera_file_path in self.included:
            logger.info('already included: {}'.format(otera_file_path.name))
            return []
        self.included.add(otera_file_path)
        logger.info('include: {}'.format(otera_file_path.name))

        otera_source = open(str(otera_file_path)).read()

        result = []  # type: List[str]
        for line in otera_source.splitlines():
            if self.is_ignored_line(line):
                continue

            m = self.library_include.match(line)
            if m:
                name = m.group(1)
                result.extend(self.expand_otera(self.find_otera(name)))
                continue

            result.append(line)
        return result

    def expand(self, source: str) -> str:
        self.included = set()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.library_include.match(line)
            if m:
                otera_path = self.find_otera(m.group(1))
                result.extend(self.expand_otera(otera_path))
                continue

            result.append(line)
        return '\n'.join(result)


if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    parser.add_argument('-c', '--console',
                        action='store_true', help='Print to Console')
    parser.add_argument('--lib', help='Path to Otera Library')
    parser.add_argument('-ac', '--atcoder', action='store_true', help='Expand ac-library')
    opts = parser.parse_args()

    lib_paths = []
    if opts.lib:
        lib_paths.append(Path(opts.lib))
    if 'CPLUS_INCLUDE_PATH' in environ:
        lib_paths.extend(
            map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))
    lib_paths.append(Path.cwd())
    expander = Expander(lib_paths)
    source = open(opts.source).read()
    output = expander.expand(source)

    if opts.console:
        print(output)
    else:
        with open('combined_otera.cpp', 'w') as f:
            f.write(output)

    if opts.atcoder:
        expande_ac_command = ["python3", fspath(PurePath(opts.lib)) + "/ac-library/expander.py", "--lib", fspath(PurePath(opts.lib)) + "/ac-library", opts.source]
        call(expande_ac_command)
