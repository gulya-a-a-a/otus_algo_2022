#!/bin/bash
MAXCOUNT=10

if [[ $1 != "" ]]; then
    MAXCOUNT=$1
fi

count=1

testsDir="tests/"

if [[ ! -d $testsDir ]]; then
    mkdir $testsDir
fi

cd "$testsDir"

filename="$MAXCOUNT.txt"

echo "$filename"

echo "$MAXCOUNT random values:"
echo "------------------------"
while [[ "$count" -le $MAXCOUNT ]]
do
    number=$RANDOM
    # echo $number
    let "count += 1"
    echo $number >> $filename
done
echo "------------------------"
