#!/bin/bash

echo "shy"
read s

case "$s" in
    Y | yes | Yes | YEs)
    echo "y"
    ;;
    N* | n*)
    echo "n"
    ;;
    *)
    exit 1
csac