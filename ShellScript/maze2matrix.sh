#!/bin/bash

input=$1
output=$(basename $1).maze
column=$2
line=$(wc -l $input | cut -d' ' -f1)
row=$(expr $line / $column)
i=1
j=1

if [ -f "$output" ]; then
  rm -f $output
fi

for n in $(cat $input | xargs echo); do
  if [ "$i" -eq 1 ] && [ "$j" -eq 1 ]; then
    echo "{" >> $output
  fi

  if [ "$i" -eq 1 ]; then
    echo -n "{ " >> $output
  fi

  if [ "$j" -eq "$row" ] && [ "$i" -eq "$column" ]; then
    echo "$n }" >> $output
    echo "};" >> $output
  elif [ "$i" -eq "$column" ]; then
    echo -ne ""$n" }, \n" >> $output
    i=1
    j=$(expr $j + 1)
  else
    echo -n ""$n", " >> $output
    i=$(expr $i + 1)
  fi
done

exit 0
