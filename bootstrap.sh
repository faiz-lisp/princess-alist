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

function die() {
    if [ -n "$1" ]; then
        echo $1
    fi
    exit 1
}

function usage() {
    echo "Usage: ./bootstrap.sh [options]"
    echo
    echo "Options:"
    echo "  -p host:port            Set up proxy"
    echo "  -h, --help, --usage     This help text"
}

enable_proxy=0

function parse_options() {
    until [ -z "$1" ]; do
        case "$1" in
            "-p")
                if [ -z "$2" ]; then
                    usage
                    die
                fi
                array=($(echo $2 | tr ":" " "))
                enable_proxy=1
                proxy_host=${array[0]}
                proxy_port=${array[1]}
                shift
                ;;

            "-h" | "--help" | "--usage" | *)
                usage
                die
                ;;
        esac
        shift
    done
}

parse_options $*

os=$(uname -s)
repo_dir="$HOME/Repositories/Git/princess-alist"
repo_home="$repo_dir/home/xiaogaozi"

if [ "$os" == "Darwin" ]; then
    ln="ln -svih"
else
    ln="ln -svin"
fi

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
git clone https://github.com/revans/bash-it.git ~/.bash_it
source ~/.bashrc

# Vim
if [ "$enable_proxy" == 1 ]; then
    curl_options="-x ${proxy_host}:${proxy_port}"
fi
curl $curl_options -Lo- https://raw.github.com/carlhuda/janus/master/bootstrap.sh | bash
$ln "$repo_home/.vimrc.before" ~/.vimrc.before
$ln "$repo_home/.vimrc.after" ~/.vimrc.after
$ln "$repo_home/.gvimrc.after" ~/.gvimrc.after

# Emacs
$ln "$repo_home/.emacs" ~/.emacs
mkdir -p ~/.emacs.d
$ln "$repo_home/.emacs.d/site-lisp" ~/.emacs.d/site-lisp

# Templates
$ln "$repo_home/.templates" ~/.templates

# # MacPorts
# if [ "$os" == "Darwin" ]; then
#     mkdir -p ~/.macports
#     $ln "$repo_home/.macports/macports.conf" ~/.macports/macports.conf
#     $ln "$repo_home/MacPorts" ~/MacPorts
# fi

# Subversion
mkdir -p ~/.subversion
if [ "$os" == "Darwin" ]; then
    $ln "$repo_home/.subversion/config.mac" ~/.subversion/config
else
    $ln "$repo_home/.subversion/config" ~/.subversion/config
fi
$ln "$repo_home/.subversion/servers" ~/.subversion/servers

git submodule init
git submodule update

exit 0
