#!/bin/bash
echo "shy"

case "$1" in 
    "one")
        echo "is one"
        ;;
    "tow")
        echo "is tow"
        ;;
    "three")
        echo "is three"
        ;;
    *)
        echo "erreor"
        ;;
esac