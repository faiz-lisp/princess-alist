#!/bin/bash

# Solution for 'Big Brother is Watching You' <http://code.google.com/p/princess-alist/>
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

s=0
i=1

for ip in `cat $1`; do
    echo $i": "$ip
    # i=`w3m -dump http://big-brother-list.appspot.com/query?ip=$ip | grep 'IP Address : ' | awk '{ print $7 }'`
    # if [ "$ip" != "$i" ]; then
    #     echo 'error: '$ip' != '$i
    # fi
    a=`w3m -dump http://big-brother-list.appspot.com/query?ip=$ip | grep -A 2 'Latitude, Longitude' | tail -n 1 | sed 's/,//' | awk '{ sum = $1 + $2; printf "%.6f", sum }'`
    s=`echo "$s+$a" | bc`
    let 'i += 1'
done

echo $s
echo -n $s | base64

exit 0
