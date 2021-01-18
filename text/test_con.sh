#! /bin/bash

num=100

#判断 0<= num <= 200
# test $num -ge 0 && test $num -le 200
test $num -ge 0 -a $num -le 200
echo "$?"

#判断 num <= 0 或者 num >= 200
test $num -le 0 | | test $num -ge 200
echo "$?"

file="file.txt"

#判断文件是否不是普通文件
test ! -f $file
echo "$?"

#判断文件是否存在并且是目录文件
test -e $file && test -d $file
echo "$?"