# Update all of my projects. <https://github.com/xiaogaozi/princess-alist>
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

svn_dir=~/Repositories/SVN/

for alist in `ls $svn_dir`; do
    if [ -d "${svn_dir}/${alist}" ]; then
        cd ${svn_dir}/${alist} && info=`svn update`
        notify-send -i "/usr/share/icons/Human/scalable/status/dialog-info.svg" "$alist" "$info"
    fi
done

cd ~/texmf/tex/latex/ctex-kit-read-only && info=`svn update`
svn rm --force xecjk
notify-send -i "/usr/share/icons/Human/scalable/status/dialog-info.svg" "ctex-kit-read-only" "$info"

exit 0
