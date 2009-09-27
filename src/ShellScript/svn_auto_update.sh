# Update all of my projects. <http://code.google.com/p/princess-alist/>
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
