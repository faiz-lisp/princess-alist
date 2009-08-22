#!/bin/bash

svn_dir=~/Project

for alist in `ls $svn_dir`; do
    if [ -d "${svn_dir}/${alist}" ]; then
        echo "${alist}:"
        cd ${svn_dir}/${alist} && svn update
        echo
    fi
done

echo "ctex-kit-read-only:"
cd ~/texmf/tex/latex/ctex-kit-read-only && svn update

exit 0
