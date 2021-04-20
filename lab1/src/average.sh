#!/bin/sh

sum=0
for num in "$@"
do
sum=$((sum+num))
done
avg=$((sum/$#))

echo "Number of arguments: $#"
echo "Average: $avg"