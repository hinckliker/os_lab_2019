#!/bin/bash
echo -n > numbers.txt 
for i in {1..150};
do 
echo "$(od -vAn -N1 -tu1 /dev/random)" >> numbers.txt
done