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

# Submodule init
git submodule init
git submodule update

# Git
$ln "$repo_home/.gitconfig" ~/.gitconfig

# Bash
$ln "$repo_home/.bash_it" ~/.bash_it
if [ "$os" == "Darwin" ]; then
    $ln "$repo_home/.bashrc.mac" ~/.bashrc
else
    $ln "$repo_home/.bashrc" ~/.bashrc
fi
$ln "$repo_home/.bash_profile" ~/.bash_profile

# Vim
if [ "$enable_proxy" == 1 ]; then
    curl_options="-x ${proxy_host}:${proxy_port}"
fi
curl $curl_options -Lo- https://raw.github.com/carlhuda/janus/master/bootstrap.sh | bash
$ln "$repo_home/.vimrc.before" ~/.vimrc.before
$ln "$repo_home/.vimrc.after" ~/.vimrc.after
$ln "$repo_home/.gvimrc.after" ~/.gvimrc.after

# Emacs
# $ln "$repo_home/.emacs" ~/.emacs
# mkdir -p ~/.emacs.d
# $ln "$repo_home/.emacs.d/site-lisp" ~/.emacs.d/site-lisp
$ln "$repo_home/.emacs.d" ~/.emacs.d
$ln "$repo_home/.emacs-live.el" ~/.emacs-live.el
$ln "$repo_home/.live-packs" ~/.live-packs

# Templates
$ln "$repo_home/.templates" ~/.templates

# src
$ln "$repo_home/src" ~/src

# # MacPorts
# if [ "$os" == "Darwin" ]; then
#     mkdir -p ~/.macports
#     $ln "$repo_home/.macports/macports.conf" ~/.macports/macports.conf
#     $ln "$repo_home/MacPorts" ~/MacPorts
# fi

# # Subversion
# mkdir -p ~/.subversion
# if [ "$os" == "Darwin" ]; then
#     $ln "$repo_home/.subversion/config.mac" ~/.subversion/config
# else
#     $ln "$repo_home/.subversion/config" ~/.subversion/config
# fi
# $ln "$repo_home/.subversion/servers" ~/.subversion/servers

# aria2
$ln "$repo_home/.aria2" ~/.aria2

# Homebrew
if [ ! $(which brew) ]; then
    ruby <(curl -fsSkL raw.github.com/mxcl/homebrew/go)
fi
brew install python
brew install gibo

# pip
if [ ! $(which pip) ]; then
    sudo easy_install pip
fi

# virtualenv and virtualenvwrapper
if [ ! $(which virtualenv) ]; then
    sudo pip install virtualenv
    sudo pip install virtualenvwrapper
    mkdir -p ~/.virtualenvs
fi

# IPython
if [ ! $(which ipython) ]; then
    sudo pip install ipython
fi

# Flake8
if [ ! $(which flake8) ]; then
    sudo pip install flake8
fi

# RVM
if [ ! $(which rvm) ]; then
    curl -L https://get.rvm.io | bash -s stable --ruby
fi

exit 0
