#!/bin/sh
count=$1
while [ $count -gt 0  ]
do
    echo $(($count-1))
    count=$(($count-1))
    #sleep 1
done
case $1
in
1) echo ashish;;
2) echo soni;;
3) echo nupur;;
4) echo soni;;
*) echo "ashish luvs nupur :)";;
esac
list=$@
echo $list
