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

ss=0  # start time, in seconds
endpos=600  # length of per file, in seconds
num=0  # number of files
file=$1
extension=`echo $file | awk -F '.' '{ print $NF }'`
if [ -z $2 ]; then
    prefix=a
else
    prefix=$2
fi

# Get length of video, in seconds.
length=`mplayer -vo null -ao null -frames 0 -identify "$file" 2> /dev/null | \
        grep '^ID_LENGTH' | sed 's/ID_LENGTH=//' | sed 's/\..*//'`

# Split file.
while [ $ss -lt $length ]; do
    let "num += 1"
    n=`printf "%03d" $num`
    f_name=${prefix}${n}.${extension}
    mencoder "$file" -ovc copy -oac copy -ss $ss -endpos $endpos -o $f_name
    echo
    echo $f_name
    echo
    let "ss += endpos"
done

exit 0
