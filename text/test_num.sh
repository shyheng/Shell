#! /bin/bash

echo "shy"
read NUM1 NUM2

test $NUM1 -eq $NUM2
echo "=?$?"

test $NUM1 -nq $NUM2
echo "!=?$?"

test $NUM1 -gt $NUM2
echo ">?$?"

test $NUM1 -ge $NUM2
echo ">=?$?"

test $NUM1 -lt $NUM2
echo "<?$?"

test $NUM1 -le $NUM2
echo "<=?$?"