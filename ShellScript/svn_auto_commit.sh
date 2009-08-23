#!/bin/bash

svn_dir=~/Project

commit ()
{
    echo "need to commit"
    echo $*
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

for alist in `ls -1 $svn_dir | grep -v 'read-only'`; do
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
