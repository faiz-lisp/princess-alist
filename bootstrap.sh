#!/bin/bash

# Bootstrap <https://github.com/xiaogaozi/princess-alist>
# Copyright (C) 2012  xiaogaozi <gaochangjian@gmail.com>
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

os=$(uname -s)
repo_dir="$HOME/Repositories/Git/princess-alist"
repo_home="$repo_dir/home/xiaogaozi"
ln="ln -svih"

function die()
{
    echo $1
    exit 1
}

if [ ! -d "$repo_dir" ]; then
    die "$repo_dir directory not found"
fi

# Bash
if [ "$os" == "Darwin" ]; then
    $ln "$repo_home/.bashrc.mac" ~/.bashrc
else
    $ln "$repo_home/.bashrc" ~/.bashrc
fi
$ln "$repo_home/.bash_profile" ~/.bash_profile
source ~/.bashrc

# Vim
# curl -Lo- https://raw.github.com/carlhuda/janus/master/bootstrap.sh | bash
$ln "$repo_home/.vimrc.after" ~/.vimrc.after
$ln "$repo_home/.gvimrc.after" ~/.gvimrc.after

# Emacs
$ln "$repo_home/.emacs" ~/.emacs
mkdir -p ~/.emacs.d
$ln "$repo_home/.emacs.d/site-lisp" ~/.emacs.d/site-lisp

# Templates
$ln "$repo_home/.templates" ~/.templates

# MacPorts
if [ "$os" == "Darwin" ]; then
    mkdir -p ~/.macports
    $ln "$repo_home/.macports/macports.conf" ~/.macports/macports.conf
    $ln "$repo_home/MacPorts" ~/MacPorts
fi

# Subversion
mkdir -p ~/.subversion
if [ "$os" == "Darwin" ]; then
    $ln "$repo_home/.subversion/config.mac" ~/.subversion/config
else
    $ln "$repo_home/.subversion/config" ~/.subversion/config
fi
$ln "$repo_home/.subversion/servers" ~/.subversion/servers

exit 0
