#! /bin/bash

echo "##"
read NUM

#注意：赋值时，等号两边不能加空格
#  []里面存放表达式时必须加空格

# 一般形式
if [ $NUM -gt 50 ]
then
    echo "NUM > 50"
fi

if [ $NUM -gt 50 ]
then
    echo "NUM > 50"
else
    echo "NUM <= 50"
fi

echo "#############"

#阶梯形式
if [ $NUM -gt 50 ] 
then
    echo ">50 "
elif [ $NUM -lt 50]
then
    echo "<50"
else
    echo "=50"
fi

echo "#############"

#嵌套形式
if [ $NUM -gt 50 ]
then
    echo ">50"
elif [ $NUM -eq 50 ]
then
    echo "=50"
else
    echo "<50"
    if [ $NUM -gt 30 ]
    then
        echo ">30"
    else
        echo "<=30"
    fi
fi