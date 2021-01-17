#! /bin/bash

echo "shy"
read FILE

test -e $FILE
echo "存？$?"

test -s $FILE
echo "非？$?"

[ -r $FILE ]
echo "读 $?"

[ -x $FILE ]
echo "执行 $?"

test -b $FILE
echo "$?"
test -c $FILE
echo "$?"
test -d $FILE
echo "$?"
test -f $FILE
echo "$?"
test -L $FILE
echo "$?"
test -S $FILE
echo "$?"
test -p $FILE
echo "$?"