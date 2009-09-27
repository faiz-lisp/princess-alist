#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Generate some feed files from you following Twitter
# users. <http://code.google.com/p/princess-alist/>
# Copyright (C) 2009  xiaogaozi <gaochangjian@gmail.com>
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

from xml.dom import minidom
import sys
import types
import re 
import urllib

def usage():
    """Print Usage"""
    print "Usage:", sys.argv[0], "[options] username1 [username2 ...]\n"
    print "This script is a tool for generating some feed files"
    print "from you following Twitter users.\n"
    print "Options:"
    print "  -h, --help\tThis help text."

def output(username, msg):
    print "user ->", username + ":", msg


def uniChr(node, attr):
    """Translate Unicode code to Unicode string."""
    v = node.attributes[attr].value
    codelist = re.findall('&#(\d+);', v)
    if len(codelist) != 0:
        for c in codelist:
            node.attributes[attr].value = re.sub('&#' + c + ';', unichr(int(c)), node.attributes[attr].value)

def fetchXML(username):
    """Fetch XML source file."""
    try:
        url = "http://tw.opml.org/get?user=" + username + "&folder=1"
        try:
            sock = urllib.urlopen(url)
            xmlsource = sock.read()
        finally:
            try:
                sock.close()
            except UnboundLocalError:
                output(username, "Connection Error")
    except IOError:
        output(username, "Connection Error")

    if xmlsource.find("INTERNAL ERROR") != -1:
        output(username, "Fetch Error. Please check your username or this guy has protected his tweets.")
        sys.exit(2)

    return xmlsource

if __name__ == "__main__":
    if sys.argv.__len__() < 2:
        usage()
        sys.exit(1)

    if sys.argv[1] == "-h" or sys.argv[1] == "--help":
        usage()
        sys.exit()

    for username in sys.argv[1:]:
        xmldoc = minidom.parseString(fetchXML(username))
        reflist = xmldoc.getElementsByTagName('outline')
        for node in reflist[0].childNodes:
            if type(node.attributes) != types.NoneType:
                uniChr(node, 'text')
                uniChr(node, 'title')

        # Write to file.
        newfile = open(username + ".opml", 'w')
        newfile.write(xmldoc.toxml().encode('utf-8'))
        newfile.close()
        output(username, "Fetch Success")
