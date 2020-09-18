# !bin/bash

make all
echo -e -n ";int;bool;bit;\n" > relatorio.csv
echo -e -n "bytes alocados (10000 numeros);" >> relatorio.csv
for i in int.out bool.out bit.out; do
    BYTES=$(valgrind --log-fd=1 ./$i 10000 | grep "bytes allocated" | cut -d " " -f11)
    echo -e -n $BYTES >> relatorio.csv
    echo -e -n ";" >> relatorio.csv
done
echo "" >> relatorio.csv
for j in {3..10}; do
    N=$((10**$j))
    echo -n -e "tempo: $N números;" >> relatorio.csv
    for i in int.out bool.out bit.out; do
        echo "FAZENDO $i COM $N NÚMEROS"
        TIME=$((time ./$i $N) 2>&1 | grep user)
        TIME=$(echo -e -n $TIME | cut -d " " -f2)
        echo -n -e $TIME >> relatorio.csv
        echo -e -n ";" >> relatorio.csv
    done
    echo "LOOP TERMINADO"
    echo "" >> relatorio.csv
done
make clear
