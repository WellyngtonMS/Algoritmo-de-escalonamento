# Algoritmo de substituição de Páginas

Neste projeto você deve escrever um programa para simular o funcionamento dos principais algoritmos de substituição de páginas estudados na disciplina.

Os algoritmos de substituição de páginas a serem implementados são os seguintes:

##### ¤ FIFO (First In, First Out)
##### ¤ OTM: Algoritmo Ótimo
##### ¤ LRU: (Least Recently Used ou Menos Recentemente Utilizado)

O seu programa deverá ler de um arquivo um conjunto de número inteiros onde o primeiro número representa a quantidade de quadros de memória disponíveis na RAM e os demais representam a sequência de referências às páginas, sempre um número por linha.

Seu programa deverá imprimir na saída o número de faltas de páginas obtido com a utilização de cada um dos algoritmos.

##### Descrição da entrada:
A entrada é composta por uma série números inteiros, um por linha, indicando, primeiro a quantidade de quadros disponíveis na memória RAM e, em seguida, a sequência de referências à memória.
##### Descrição da saída:
A saída é composta por linhas contendo a sigla de cada um dos três algoritmos e a quantidade de faltas de página obtidas com a utilização de cada um deles.

##### Exemplo de entrada
```
4
1
2
3
4
1
2
5
1
2
3
4
5
```

##### Exemplo de saída
```
FIFO 10
OTM 6
LRU 8
```

##### Exemplo de entrada
```
3
7
0
1
2
0
3
0
4
2
3
0
3
2
1
2
0
1
7
0
1
```

##### Exemplo de saída
```
FIFO 15
OTM 9
LRU 12
```

##### Exemplo de entrada
```
3
0
2
1
3
5
4
6
3
7
4
7
3
3
5
5
3
1
1
1
7
1
3
4
1
```

##### Exemplo de saída
```
FIFO 15
OTM 11
LRU 14
```

##### Exemplo de entrada
```
7
0
2
1
3
5
4
6
3
7
4
7
3
3
5
5
3
1
1
1
7
1
3
4
1
```

##### Exemplo de saída
```
FIFO 8
OTM 8
LRU 8
```

##### Corretude
O programa deve ler a entrada e imprimir a saída EXATAMENTE como no formato especificado acima. A impressão de qualquer outro caractere ou de dados fora da ordem solicitada implicará em uma saída incorreta.

##### Exemplo de saída do arquivo teste

Quadros | FIFO | LRU | OTM
:---------: | :------: | :------: | :------:
64     | 38496 | 30416 |18377
256    | 9859 | 6270 | 3107
1024   | 1450 | 1273 | 1260
4096  | 1260 | 1260 | 1260

** Caso utilize o arquivo teste, não esqueça de alterar a primeira linha do arquivo para os valores de _"quadros"_ desejado, conforme tabela acima.
