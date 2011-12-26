#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Check if any of my SVN working copy need to commit. <http://code.google.com/p/princess-alist/>
# Copyright (C) 2010  xiaogaozi <gaochangjian@gmail.com>
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
import fnmatch
import ConfigParser
import subprocess as sub
from os import path

CONFIG_FILE = "config"

def parse_config():
    """Parse configuration file."""
    config = ConfigParser.RawConfigParser()
    if sys.platform == 'win32':
        config.read(path.join(os.environ['APPDATA'], "Chameleon\\" + CONFIG_FILE))
    else:
        config.read(path.join(os.environ['HOME'], ".chameleon/" + CONFIG_FILE))
    r = config.get('svn', 'root_dirs').replace('\n', '').split(',')
    if r == '':
        raise ValueError("root_dirs is necessary, please check configuration file")
    e = config.get('svn', 'exclude_dirs').replace('\n', '').split(',')

    root_dirs = [path.normpath(path.expanduser(path.expandvars(d))).strip()
                 for d in r]
    exclude_dirs = [path.normpath(path.expanduser(path.expandvars(d))).strip()
                    for d in e]

    return root_dirs, exclude_dirs

def is_exclude(root_dir, entry, exclude_dirs):
    """Verify if this entry in the exclude_dirs list."""
    for d in exclude_dirs:
        if path.dirname(d) == '':
            if fnmatch.fnmatch(entry, d) == True:
                return True
        else:
            if fnmatch.fnmatch(path.join(root_dir, entry), d) == True:
                return True
    return False

def has_change(root_dir, entry, output):
    """Verify if this working copy has changed."""
    p = sub.Popen('svn status "%s"' % entry, stdout=sub.PIPE, stderr=sub.PIPE, shell=True,
                  cwd=root_dir)
    stdoutdata, stderrdata = p.communicate()
    if stdoutdata == '':
        return False
    output.append(stdoutdata)
    return True

def parse_output(root_dir, entry, output):
    """Parse output of SVN status.
    
    return True: there are some items could be committed (i.e. have items
                 besides question mark items)
    return False: they are all question mark items"""
    question_items = get_question_items(root_dir, output)
    if len(question_items) == 0:
        return True

    print "some items aren't under version control, apply to them?"
    print "[a] apply to all"
    print "[e] decide on each item"
    print "[q] leave them alone"

    while True:
        inputs = raw_input()
        if inputs == '':
            continue

        c = inputs[0]
        if c in ['a', 'A']:
            for v in question_items.itervalues():
                os.system('svn add "%s"' % v)
            return True
        elif c in ['e', 'E']:
            for k, v in question_items.iteritems():
                if sys.platform == 'win32':
                    sys.stdout.write('\b')
                inputs = raw_input(k + ": apply [Y/n]? ")
                if inputs == '':
                    continue
                c = inputs[0]
                if c in ['y', 'Y']:
                    os.system('svn add "%s"' % v)
                else:
                    continue
            out = []
            has_change(root_dir, entry, out)
            output = out[0]
            break
        elif c in ['q', 'Q']:
            break
        else:
            if sys.platform == 'win32':
                sys.stdout.write('\b')
            print "invalid input, try again: ",

    question_items.clear()
    question_items = get_question_items(root_dir, output)
    if len(question_items) == len(output.split('\n')) - 1:
        return False
    else:
        return True

def get_question_items(root_dir, output):
    """Get question mark items from output (if there is any)."""
    question_items = {}
    for line in output.split('\n'):
        if re.search('^\?.*', line) != None:
            m = re.search('^\?\s*([^\s]*)\s*', line)
            d = path.join(root_dir, m.group(1))
            question_items[m.group(1)] = path.normpath(d)
    return question_items

def commit(root_dir, entry):
    """Commit to repository."""
    absolute_path = path.join(root_dir, entry)
    os.system('svn update "%s"' % absolute_path)
    os.system('svn commit "%s"' % absolute_path)
    os.system('svn update "%s"' % absolute_path)

def main():
    """Main progress."""
    root_dirs, exclude_dirs = parse_config()
    for root_dir in root_dirs:
        for entry in os.listdir(root_dir):
            absolute_path = path.join(root_dir, entry)
            if path.isdir(absolute_path) == False:
                continue
            # This directory is a Subversion working copy.
            if '.svn' in os.listdir(absolute_path):
                if is_exclude(root_dir, entry, exclude_dirs) == True:
                    continue
                print "%s (%s):" % (entry, root_dir),
                output = []
                if has_change(root_dir, entry, output) == False:
                    print "nothing to do\n"
                    continue
                print '\n' + output[0],
                if parse_output(root_dir, entry, output[0]) == False:
                    print
                    continue
                if sys.platform == 'win32':
                    sys.stdout.write('\b')
                inputs = raw_input("commit now [Y/n]? ")
                if inputs == '':
                    print
                    continue
                c = inputs[0]
                if c in ['Y', 'y']:
                    commit(root_dir, entry)
                print

if __name__ == "__main__":
    main()
