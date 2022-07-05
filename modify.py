#!/usr/bin/env python3

#!/usr/bin/env python3

# This code is based on [ac-lirary](https://github.com/atcoder/ac-library)'s expander.py.

import re
import sys
import argparse
from os import getenv, environ, pathsep, fspath
from pathlib import Path, PurePath

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    parser.add_argument('--lib', help='Path to Otera Library')
    opts = parser.parse_args()
    
    lib_paths = []
    if opts.lib:
        lib_paths.append(Path(opts.lib))
    else:
        print("[ERROR] CAN NOT FIND LIB_PATH")
        exit(0)
    
    modify_file = "modify.cpp"
    modify_writer = open(modify_file, "w")
    target_reader = open(opts.source).read()
    for line in target_reader.splitlines():
        if line == "#include<bits/stdc++.h>":
            for line2 in open(opts.lib+"/modify_template.cpp").read().splitlines():
                modify_writer.write(line2)
                modify_writer.write("\n")
        else:
            modify_writer.write(line)
            modify_writer.write("\n")
            
    modify_writer.close()
    
    print("[INFO] generate modify.cpp")
    

    
