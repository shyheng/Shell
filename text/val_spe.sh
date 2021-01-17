#! /bin/bash

name="zhang"
#双引号里面的特殊字符 会使用其特殊含义
str="$name"
#单引号里面的特殊字符 都会失去特殊含义
str1='$name'

echo str
echo str1

#反引号 获取一个shell命令的输出结果，一般对有输出结果的命令经常使用，也可以使用$()与反引号等价
echo "is `date`"
echo 'is `date`'

# 转字符：使用时，需要在echo后面加上-e选项
echo "##########"
echo "this \n is \ta\ntest" 
echo -e "this \n is \ta\ntest"
echo "##########"

num=100
#由子shell来完成，不影响当前shell中的变量
( num=90;echo "1 $num")
echo 1:$num
#在当前shell中执行，会影响当前变量
{ num=60; echo "2 $num"}
echo 2:$num