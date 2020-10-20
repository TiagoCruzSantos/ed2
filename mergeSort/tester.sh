#! /bin/bash

BINARIES=$1
INPUT_FILES=$2
echo -n "" > output.csv
for i in $INPUT_FILES; do
    echo -n ",${i}" >> output.csv
done
echo "" >> output.csv
for i in $BINARIES; do
    echo -n $i >> output.csv
    for j in $INPUT_FILES; do
        NUMBER=$(echo $j | tr -dc '0-9')
        TIME=$(./$i $NUMBER < $j)
        echo -n ",${TIME}" >> output.csv
    done
    echo "" >> output.csv
done