#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Batch rename utility. <http://code.google.com/p/princess-alist/>
# Copyright (C) <2011>  xiaogaozi <gaochangjian@gmail.com>
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
import re
import sys

def usage():
    """Usage"""
    print "Usage: rename.py expr files"

def main():
    """Main progress."""
    if len(sys.argv) < 3:
        usage()
        sys.exit(1)

    expr = sys.argv[1]
    m = re.search(r'^[sy]/([^/]*)/([^/]*)/$', expr)
    if m is None:
        sys.stderr.write("expression incorrect\n")
        sys.exit(1)
    re1 = m.group(1)
    re2 = m.group(2)  # actually in substitute mode this portion is not regular expression

    for oldfile in sys.argv[2:]:
        d = os.path.dirname(oldfile)
        oldname = os.path.basename(oldfile)
        newname = ''
        newfile = ''
        if expr[0] == 's':  # substitute
            newname = re.sub(re1, re2, oldname)
            newfile = os.path.join(d, newname)
            os.rename(oldfile, newfile)
        elif expr[0] == 'y':  # transliterate
            pass
        print oldfile, '->', newfile

if __name__ == "__main__":
    main()
