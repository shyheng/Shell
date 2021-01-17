#!/bin/bash

#定义变量
#shell脚本中没有数据类型可言 禁止有空格
NUM=100

#引用变量
# $变量名 取一个变量的值
i=$NUM

#显示变量
echo $NUM
echo $i

#清除变量
unset NUM
echo "#############"
echo $NUM

#使用read从终端读取数据保存变量
read str
echo "str = $str"

#使用readonly创建一个只读的变量
readonly n=999
echo "n = $n"

# n=66
# echo "n = $n"