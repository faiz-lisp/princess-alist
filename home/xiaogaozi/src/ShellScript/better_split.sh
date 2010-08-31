#!/bin/bash

# Split video file into many small parts. <http://code.google.com/p/princess-alist/>
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

usage ()
{
    echo "Usage: better_split.sh [options] <filename>"
    echo
    echo "Options:"
    printf "  -p, --prefix=PREFIX   Override default filename prefix ('a').\n"
    printf "  -h, --help            This help text.\n"
}

if [ $# -lt 1 ]; then
    usage
    exit 1
fi

# Parse options.
while [ $# -ne 0 ]; do
    option=$1
    shift

    case $option in
        -p)
            prefix=$1
            if [ -z $prefix ]; then
                echo "Prefix needed, use -h for more information."
                exit 1
            fi
            shift
            ;;

        --prefix=*)
            prefix=`echo $option | sed 's/--[^=]*=//'`
            if [ -z $prefix ]; then
                echo "Prefix needed, use -h for more information."
                exit 1
            fi
            ;;

        -h | --help)
            usage
            exit 0
            ;;

        *)
            file=$option
            if [ ! -e "$file" ]; then
                echo "${file}: No such file or directory"
                exit 1
            fi
            ;;
    esac
done

if [ -z "$file" ]; then
    echo "Filename needed, use -h for more information."
    exit 1
fi

# Use default prefix.
if [ -z $prefix ]; then
    prefix=a
fi

ss=0  # start time, in seconds
endpos=600  # length of per file, in seconds
num=0  # number of files
extension=`echo $file | awk -F '.' '{ print $NF }'`

# Get length of video, in seconds.
length=`mplayer -vo null -ao null -frames 0 -identify "$file" | \
        grep '^ID_LENGTH' | sed 's/ID_LENGTH=//' | sed 's/\..*//'`
if [ -z $length ]; then
    echo "${file}: File doesn't supported."
    exit 1
fi

# Split file.
while [ $ss -lt $length ]; do
    let "num += 1"
    n=`printf "%03d" $num`
    f_name=${prefix}${n}.${extension}
    mencoder "$file" -ovc copy -oac copy -ss $ss -endpos $endpos -o $f_name
    echo
    echo ">>>> "$f_name
    echo
    let "ss += endpos"
done

exit 0
