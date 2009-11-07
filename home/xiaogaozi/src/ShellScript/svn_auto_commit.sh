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

svn_dir=~/Project

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
    echo -n "commit now [Y/N]? "
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
                read -p "wrong input, again [Y/N]? " a
                ;;
        esac
    done
}

# Synchronise some my source codes between repository and local computer.
pasync ()
{
    basepath=${svn_dir}/princess-alist
    destpath=~/src

    cd $basepath
    for blist in `ls $basepath`; do
        if [ -d "${basepath}/${blist}" ]; then
            case "$blist" in
                "templates" )
                    cp -rf ${blist}/* ~/.templates/
                    ;;

                "sources.list.d" )
                    sudo cp -rf ${blist}/* /etc/apt/sources.list.d/
                    ;;

                * )
                    cp -rf $blist $destpath
                    ;;
            esac
        fi
    done
    find $destpath \( -name '.svn' -o -name '*.swp' \) -exec rm -rf {} \; 2> /dev/null

    echo "Sync Over"
}

for alist in `ls -1 $svn_dir | grep -v 'read-only'`; do
    if [ $alist == "princess-alist" ]; then
        pasync
    fi

    if [ -d "${svn_dir}/${alist}" ]; then
        echo -n "${alist}: "
        cd ${svn_dir}/${alist} && status_info=`svn status`
        if [ -n "$status_info" ]; then
            commit $status_info
        else
            echo
        fi
        echo
    fi
done

exit 0
