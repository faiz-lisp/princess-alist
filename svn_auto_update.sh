#!/bin/bash

svn_dir=~/Project

for alist in `ls $svn_dir`; do
    if [ -d "${svn_dir}/${alist}" ]; then
        cd ${svn_dir}/${alist}
        echo "${alist}:"
        svn update
        echo
    fi
done

exit 0
