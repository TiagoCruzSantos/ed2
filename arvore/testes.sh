#!/bin/bash

# $1 - executavel
# $2 - k vezes rodar o programa
# $3 - n numeros pra inserir

I=0
HIGHT_AT=""
HIGHT_SUM=0
LIST_VALUES=""

# $1 - lista
# $2 - qtd
function mean(){
    local SUM=0
    for I in $1; do
        SUM=$(expr $SUM + $I)
    done
    RESULT=$(echo $SUM/$2 | bc -l)
    echo $RESULT
}

# $1 - lista
# $2 - media
# $3 - qtd
function sd(){
    local SUM=0
    local STD_UNSQRT=""
    for I in $1; do
        SUM=$(echo "$SUM+($I - $2)^2" | bc -l)
    done
    STD_UNSQRT=$(echo "$SUM/$3" | bc -l)
    STD=$(echo "sqrt($STD_UNSQRT)" | bc -l)
    echo $STD
}

while [[ $I -lt $2 ]]; do
    echo "Loop numero $I"
    HIGHT_AT=$(./$1 $3)
    echo "Tamanho arvore atual: $HIGHT_AT"
    LIST_VALUES="$LIST_VALUES $HIGHT_AT"
    HIGHT_SUM=$(expr $HIGHT_SUM + $HIGHT_AT)
    I=$(expr $I + 1)
done
MEAN=$(mean "$LIST_VALUES" $2)
STANDARDD=$(sd "$LIST_VALUES" $MEAN $2)
echo "Soma: $HIGHT_SUM, Media: $MEAN, Desvio padrão: $STANDARDD"