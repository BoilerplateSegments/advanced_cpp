#!/usr/bin/env python3
import os
import sys
from shutil import copyfile as CP

if len(sys.argv) != 2:
    print("\033[31;1m" + "need name for new file" + "\033[0m")
    exit(1)

biggest = 0

for file in os.listdir("."):

    if file[0:2].isnumeric():
        index = int(file[0:2])

        if index > biggest:
            biggest = index

biggest += 1

cmd_name = sys.argv[1]

bare_name = '{0:02}'.format(biggest) + '_' + cmd_name

# TODO: use format tempalte rather than raw file copy
CP("00_template.h", bare_name + '.h')
CP("00_template.cpp", bare_name + '.cpp')
CP("00_template_test.cpp", bare_name + '_test.cpp')
