#! /bin/bash

myadd()
{
    # shell函数传参
    # shell函数中想要传参 不能在函数名后的括号里面定义
    # 而是使用$1 $2 ..保存外部传入的值
    A=$1
    B=$2

    SUM=`expr $A + $B`
    echo "$A + $B = $SUM"
}

#带参数的shell函数的调用
myadd 100 200

num1=66
num2=44
myadd $num1 $num2