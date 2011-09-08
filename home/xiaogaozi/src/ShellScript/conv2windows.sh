#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: conv2windows.sh [FILENAME]..."
  exit 1
fi

echo -e "\033[01;34m##### Begin Conversition #####"
echo -e "\033[00m"

errorfile=conv2windows.$(date +%Y.%m.%d).log

for file in $*; do
  filename=$(basename $file)
  convfile="$file".win
  tempfile="$file".tmp
  temperrorfile="$file".log

  if [ -f "$temperrorfile" ]; then
    rm -f $temperrorfile
  fi

  # Convert encode from UTF-8 to GB2312.
  echo -en "\033[01;33m"$filename"\033[00m: convert encode... "
  iconv -cs -t GB2312 $file > $tempfile 2>> $temperrorfile
  echo -e "\033[01;32mdone"
  echo -en "\033[00m"

  # Add the tail of line.
  echo -en "\033[01;33m"$filename"\033[00m: add <CR>... "
  cat $tempfile | sed 's/\n/\r\n/g' > $convfile 2>> $temperrorfile
  echo -e "\033[01;32mdone"
  echo -en "\033[00m"

  line=$(wc -l $convfile | cut -d' ' -f1)
  echo -e "total: \033[01;32m$line \033[00mline(s) in output file \033[01;33m$convfile"
  rm -f $tempfile

  # Store errors in one error file.
  if [ -f "$temperrorfile" ] && [ -n "$(head -n 1 $temperrorfile)" ]; then
    echo ">>>>>> $file <<<<<<" >> $errorfile
    cat $temperrorfile >> $errorfile
    echo >> $errorfile
  fi
  rm -f $temperrorfile 2> /dev/null

  echo
done

echo -e "\033[00mTotal \033[01;32m"$#" \033[00mfile(s) have been converted."
if [ -f "$errorfile" ] && [ -n "$(head -n 1 $errorfile)" ]; then
  echo -e "\033[01;31mNOTE: \033[00mThere's something wrong occured. See the log file \033[01;33m$errorfile \033[00mfor more information."
else
  rm -f $errorfile 2> /dev/null
fi
echo
echo -e "\033[01;34m##### Conversition Complete #####"

exit 0
