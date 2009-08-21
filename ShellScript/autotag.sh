#!/bin/bash

if which ctags > /dev/null; then
  echo "Hey, I get it!" > /dev/null
else
  echo "ctags is needed"
  exit 1
fi

base_dir=$(pwd)
extension="([cC]|[cC][pP][pP]|[hH])"

for dir in $(find $base_dir -type d)
do
  cd $dir
  file=$(find . -maxdepth 1 -regextype posix-egrep -regex ".*\."$extension"" | head -n 1)
  if [ -n "$file" ]; then
    ctags -R $base_dir
  fi
done

exit 0
