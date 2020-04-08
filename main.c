#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "biblioteca.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TmoduloPagina auxiliar;
    int numeroQuadros = 0, numeroFalta = 0, numeroLinha = 0;
    char nome[50];

    printf("> Digite o nome do arquivo com extensão (Ex.: arquivo.txt)\n> ");
    scanf("%s", nome);
    fflush(stdin);

    contarPaginas(nome, &numeroLinha);
    lerArquivo(nome, &auxiliar, &numeroQuadros, numeroLinha);

    numeroFalta = FIFO(auxiliar, numeroQuadros);
    printf("\nFIFO %d\n", numeroFalta);
    fflush(stdin);

    numeroFalta = OTM(auxiliar, numeroQuadros);
    printf("OTM %d\n", numeroFalta);
    fflush(stdin);

    numeroFalta = LRU(auxiliar, numeroQuadros);
    printf("LRU %d\n", numeroFalta);
    fflush(stdin);

    return 0;
}
