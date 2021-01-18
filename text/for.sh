#!/bin/bash

# 声明sum变量是一个整数变量，准备保存整数
declare -i sum

for (( i=1; i<=100; i++))
do
    sum=sum+i
done

echo "is $sum"