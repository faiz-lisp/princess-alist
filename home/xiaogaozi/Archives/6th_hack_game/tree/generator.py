#!/usr/bin/env python
# -*- coding: utf-8 -*-

# <one line to give the program's name and a brief idea of what it does.> <project url>
# Copyright (C) <year>  xiaogaozi <gaochangjian@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import os
import random

ALPH = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

def foo(time):
    """"""
    if time == 3:
        filename = random.choice(ALPH) + str(random.getrandbits(64)) + random.choice(ALPH)
        content = random.choice(ALPH) + str(random.getrandbits(64)) + random.choice(ALPH)
        file = open(filename, 'w')
        file.write(content)
        file.close()
        return
    else:
        time = time + 1

    while True:
        d1 = random.choice(ALPH) + str(random.getrandbits(64)) + random.choice(ALPH)
        d2 = random.choice(ALPH) + str(random.getrandbits(64)) + random.choice(ALPH)
        if d1 != d2:
            break

    cwd = os.getcwd()

    os.mkdir(d1)
    os.chdir(d1)
    foo(time)

    os.chdir(cwd)

    os.mkdir(d2)
    os.chdir(d2)
    foo(time)

def main():
    foo(0)

if __name__ == "__main__":
    main()
