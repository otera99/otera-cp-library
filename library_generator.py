#!/usr/bin/env python3

import re
from logging import Logger, basicConfig, getLogger
from os import getenv, path, listdir
from shutil import copy

FILE_PATH = 'library'
OTERA_PATH = 'otera'

logger = getLogger(__name__)  # type: Logger

class Generator:
    library_include = re.compile(
        r'#include\s*["<](library/[a-z_/A-Z]*(|.hpp))[">]\s*')

    def __init__(self):
        pass

    def extract_library_name(self, lib_include):
        ret = ""
        for i in range(len(lib_include)):
            if lib_include[i] == '/':
                ret = ""
            elif lib_include[i] == '.':
                return ret
            else:
                ret += lib_include[i]

    def generate(self, lib_path, file_name, otera_path, otera_all_file):
        print("[INFO] generate: " + file_name)
        # copy(lib_path, otera_path + '/' + file_name)
        otera_file = open(otera_path + '/' + file_name, "w")
        lib_file = open(lib_path).read()
        for line in lib_file.splitlines():
            if self.library_include.match(line):
                otera_file.write("#include<otera/" + self.extract_library_name(line) + ">")
                otera_file.write('\n')
                continue
            otera_file.write(line)
            otera_file.write('\n')
        otera_file.close()
        print("[INFO] generate: " + file_name[:-4])
        new_file_path = otera_path + '/' + file_name[:-4]
        new_file = open(new_file_path, 'w')
        file_include = "#include <" + otera_path + '/' + file_name + '>'
        new_file.write(file_include)
        otera_all_file.write(file_include)
        otera_all_file.write('\n')
        new_file.close()

    def file_check(self, lib_path, file_name, otera_all_file):
        if path.isdir(lib_path):
            files = listdir(lib_path)
            for file in files:
                self.file_check(lib_path + '/' + file, file, otera_all_file)

        else:
            if lib_path[-4:] == '.hpp':
                self.generate(lib_path, file_name, OTERA_PATH, otera_all_file)

if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    otera_all_file = open(OTERA_PATH + "/all", "w")
    generator = Generator()
    generator.file_check(FILE_PATH, '', otera_all_file)
    print("[INFO] generate: all")
    otera_all_file.close()