#!/usr/bin/env python
# -*- coding: utf-8 -*-

from xml.dom import minidom
import sys
import types
import re 

def uniChr(node, attr):
    """Translate Unicode code to Unicode string."""
    v = node.attributes[attr].value
    codelist = re.findall('&#(\d+);', v)
    if len(codelist) != 0:
        for c in codelist:
            node.attributes[attr].value = re.sub('&#' + c + ';', unichr(int(c)), node.attributes[attr].value)

if __name__ == "__main__":
    xmldoc = minidom.parse(sys.argv[1])
    reflist = xmldoc.getElementsByTagName('outline')
    for node in reflist[0].childNodes:
        if type(node.attributes) != types.NoneType:
            uniChr(node, 'text')
            uniChr(node, 'title')

    newfile = open('trans_' + sys.argv[1], 'w')
    newfile.write(xmldoc.toxml().encode('utf-8'))
    newfile.close()
