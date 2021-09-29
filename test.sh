#!/bin/bash

for i in `seq 1 1000`
do
    ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG
done
