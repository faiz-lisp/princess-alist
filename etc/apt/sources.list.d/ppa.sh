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

prefix=/etc/apt/sources.list.d

if [ ! -f ${prefix}/docky*.list ]; then
    echo "Add Software Source of Docky:"
    sudo add-apt-repository ppa:docky-core/ppa
    echo
fi

if [ ! -f ${prefix}/elementaryart*.list ]; then
    echo "Add Software Source of elementary Desktop:"
    sudo add-apt-repository ppa:elementaryart/elementarydesktop
    echo
fi

if [ ! -f ${prefix}/shutter*.list ]; then
    echo "Add Software Source of Shutter:"
    sudo add-apt-repository ppa:shutter/ppa
    echo
fi

if [ ! -f ${prefix}/songbird*.list ]; then
    echo "Add Software Source of Songbird:"
    sudo add-apt-repository ppa:songbird-daily/ppa
    echo
fi

if [ ! -f ${prefix}/globalmenu*.list ]; then
    echo "Add Software Source of Global Menu:"
    sudo add-apt-repository ppa:globalmenu-team/ppa
    echo
fi

if [ ! -f ${prefix}/tiheum*.list ]; then
    echo "Add Software Source of Equinox GTK Engine and Faenza Icon Theme:"
    sudo add-apt-repository ppa:tiheum/equinox
    echo
fi

sudo apt-get update

# Global Menu
sudo apt-get install gnome-globalmenu

# Equinox GTK Engine and Faenza Icon Theme
sudo apt-get install gtk2-engines-equinox equinox-theme equinox-ubuntu-theme faenza-icon-theme

exit 0
