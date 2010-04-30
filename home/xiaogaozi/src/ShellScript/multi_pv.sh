#!/bin/bash

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

usage ()
{
    echo "Usage: multi_pv.sh <directory> files ..."
}

if [ "$#" -lt "2" ]; then
    usage
    exit 1
fi

# Destination must be a directory.
dest=$1
if [ ! -d "$dest" ]; then
    usage
    exit 1
fi

dest=`echo $dest | sed 's/\/$//'`

shift
for file in $@; do
    if [ -d $file ]; then
        echo
        echo "$file is not a file, abort it."
        echo
        continue
    fi

    path=${dest}/`basename $file`
    overwrite=1  # true
    if [ -e $path ]; then
        read -p "File $path has existed, overwrite it? [Y/n] " choice
        while true; do
            case "$choice" in
                "Y" | "y" )
                    break
                    ;;

                "N" | "n" )
                    overwrite=0  # false
                    break
                    ;;

                * )
                    read -p "Invalid input, overwrite it? [Y/n] " choice
                    ;;
            esac
        done
    fi

    if [ "$overwrite" -eq "0" ]; then
        continue
    fi

    echo
    echo ">>>> $file ==> $path"
    pv $file > $path
    echo
done

exit 0
