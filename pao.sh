#!/usr/bin/env bash
(
if [ $1 -eq 0 ]
then
    echo "if 执行了。。"
    make clean
else
    make grammar
    make parser
    cd output
    make 
fi
)


