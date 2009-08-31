#!/bin/bash

svn_dir=~/Project

output_status ()
{
    i=0
    for a in `echo $*`; do
        if [ $i -ne 2 ]; then
            echo -n "$a "
        else
            echo
            echo -n "$a "
            i=0
        fi
        i=`expr $i + 1`
    done
    echo
}

commit ()
{
    echo "need to commit"
    output_status $*
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

pasync ()
{
    basepath=${svn_dir}/princess-alist

    cd $basepath
    for blist in `ls $basepath`; do
        if [ -d "${basepath}/${blist}" ]; then
            if [ $blist == "templates" ]; then
                cp -rf ${blist}/* ~/.templates/
            else
                cp -rf $blist ~/src/
            fi
        fi
    done

    echo "Sync Over"
}

for alist in `ls -1 $svn_dir | grep -v 'read-only'`; do
    if [ $alist == "princess-alist" ]; then
        pasync
    fi

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
