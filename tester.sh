#!/bin/sh

i=0
clear;
while true;do
    i=$((i+1))
    ./math-skills-tester > tester;
    ./math-skills data.txt > my;
    diff tester my;
    if [ $? -eq 1 ]; then
        echo "an error has been founded"
        break
    fi
    if [ $i -eq 10000 ]; then
        echo "the test is pass"
        break
    fi
done
rm ./tester;
rm ./my;
