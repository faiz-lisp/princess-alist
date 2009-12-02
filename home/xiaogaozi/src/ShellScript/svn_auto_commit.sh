# Check if any of my projects need to commit. <http://code.google.com/p/princess-alist/>
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

svn_dir=~/Repositories/SVN
exclude_dir="(read-only$|depot-tools)"

output_status ()
{
    i=0
    for a in `echo $*`; do
        if [ $i -ne 2 ]; then
            echo -n "$a "
        else
            echo
            echo -n "$a "
            i=0
        fi
        i=`expr $i + 1`
    done
    echo
}

commit ()
{
    echo "need to commit"
    output_status $*
    echo -n "commit now [Y/n]? "
    read a
    while true; do
        case "$a" in
            "Y" | "y" )
                svn commit
                return
                ;;

            "N" | "n" )
                return
                ;;

            * )
                read -p "wrong input, again [Y/n]? " a
                ;;
        esac
    done
}

if [ ! -d "$svn_dir" ]; then
    echo "Error: ${svn_dir} is not a directory or doesn't exist."
    exit 1
fi

for alist in `ls -1 $svn_dir | egrep -v "$exclude_dir"`; do
    if [ -d "${svn_dir}/${alist}" ]; then
        echo -n "${alist}: "
        cd ${svn_dir}/${alist} && status_info=`svn status`

        # Check if need to commit.
        if [ -n "$status_info" ]; then
            commit $status_info
        else
            echo "nothing to do"
        fi

        echo
    fi
done

exit 0
