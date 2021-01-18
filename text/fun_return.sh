#! /bin/bash

myadd()
{
    A=$1
    B=$2

    SUM=`expr $A + $B`

    return $SUM
}

myadd 10 20
#函数的返回值一般通过$?可以获取，但是最大值是255
echo "$?"

myadd 100 200
# echo "$?"
# 在shell中，除了（）中定义的变量，只要不做任何修饰
# 都可以认为是全局变量， 在任意一个位置调用
echo "SUM=$SUM"