#! /bin/bash

test "hello" = "hello"
echo "=？$?"

test "hello" = "hel"
echo "=？$?"

test "hello" != "hello"
echo "!=？$?"

test "hello" != "hel"
echo "=？$?"

test -z "hello" 
echo "长度？$?"

test -n "hello" 
echo "长度！=0？$?"