#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

//--- função auxiliar para contar as linnhas do arquivo fornecido, ou seja, conta quantas páginas tem no arquivo
void contarPaginas(char *nomeArquivo, int *numero){
    char c;
    char letra = '\n';

    FILE *file_descriptor;
	file_descriptor = fopen(nomeArquivo, "r");
	if(file_descriptor == NULL){
        printf("Problemas na abertura do arquivo ou arquivo inexistente!\n");
        exit(1);
	}
    while(fread(&c, sizeof(char), 1, file_descriptor)){
        if(c == letra){
            *numero = *numero+1;
        }
	}
	fclose(file_descriptor);
}

//--- função que faz a leitura do arquivo e insere os valores lidos em suas respectivas variáveis, primeiro valor nº de quadros e o restante páginas
void lerArquivo(char *nomeArquivo, TmoduloPagina *auxiliar, int *quadros, int numero){
    int pagina, i = 0;
    auxiliar->vetor = malloc(numero *sizeof(TmoduloNumero));
    memset(auxiliar->vetor, 0, numero *sizeof(auxiliar->vetor[0]));
    auxiliar->numeroPaginas = numero;

    FILE *file_descriptor;
	file_descriptor = fopen(nomeArquivo, "r");
	if(file_descriptor == NULL){
        printf("Problemas na abertura do arquivo ou arquivo inexistente!\n");
        exit(1);
	}
    fscanf(file_descriptor, "%d", quadros);
	while((fscanf(file_descriptor, "%d", &pagina)) != EOF){
        auxiliar->vetor[i].valor = pagina;
        auxiliar->vetor[i].flag = 0;
        i++;
	}

	fclose(file_descriptor);
}

//--- função de implementação do algoritmo de substituição de páginas FIFO (First In First Out)
int FIFO(TmoduloPagina auxiliar, int quadros){
    TmoduloVetor *vetorQuadros;
    vetorQuadros = malloc(quadros *sizeof(TmoduloVetor));

    int i = 0, j = 0, k = 0, numeroFaltas = 0, flag = 0, cont = 0, n = 0;

    for(i = 0; i < auxiliar.numeroPaginas; i++){
        if(cont < quadros){
            for(k = 0; k < n; k++){
                if(auxiliar.vetor[i].valor == vetorQuadros[k].valor){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                vetorQuadros[cont].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
                cont++;
                n++;
            }
        }
        else{
            for(k = 0; k < quadros; k++){
                if(auxiliar.vetor[i].valor == vetorQuadros[k].valor){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                vetorQuadros[j].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
                j++;
                if(j == quadros){
                    j = 0;
                }
            }
        }
    }
    free(vetorQuadros);

    return numeroFaltas;
}

//--- função auxiliar para contar qual página do vetor de quadros está mais distante, ou seja, a que ficará mais tempo sem ser usada
void procuraOTM(TmoduloPagina auxiliar, TmoduloVetor *vetor, int quadros, int x){
    int i = 0, j = 0;
    for(i = 0; i < quadros; i++){
        for(j = x; j < auxiliar.numeroPaginas; j++){
            if(vetor[i].valor == auxiliar.vetor[j].valor){
                vetor[i].distancia = j+1;
                break;
            }
        }
    }

}

//--- função de implementação do algoritmo de substituição de páginas OTM (Ótimo)
int OTM(TmoduloPagina auxiliar, int quadros){
    TmoduloVetor *vetorQuadro;
    vetorQuadro = malloc(quadros *sizeof(TmoduloVetor));

    int i = 0, j = 0, k = 0, numeroFaltas = 0, cont = 0, flag = 0, n = 0;

    for(i = 0; i < auxiliar.numeroPaginas; i++){
        if(cont < quadros){
            for(k = 0; k < n; k++){
                if(auxiliar.vetor[i].valor == vetorQuadro[k].valor){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                vetorQuadro[cont].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
                cont++;
                n++;
            }
        }
        else{
            for(k = 0; k < quadros; k++){
                if(auxiliar.vetor[i].valor == vetorQuadro[k].valor){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                for(k = 0; k < quadros; k++){
                    vetorQuadro[k].distancia = 0;
                }
                procuraOTM(auxiliar, vetorQuadro, quadros, i);

                int d = 0;
                for(k = 0; k < quadros; k++){
                    if(vetorQuadro[k].distancia == 0){
                        j = k;
                        break;
                    }
                    else if(d < vetorQuadro[k].distancia){
                        d = vetorQuadro[k].distancia;
                        j = k;
                    }
                }
                vetorQuadro[j].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
            }
        }
    }
    free(vetorQuadro);
    return numeroFaltas;
}

//--- função de implementação do algoritmo de substituição de páginas LRU (Least Recently Used)
int LRU(TmoduloPagina auxiliar, int quadros){
    TmoduloVetor *vetorQuadros;
    vetorQuadros = malloc(quadros *sizeof(TmoduloVetor));

    int i = 0, j = 0, k = 0, numeroFaltas = 0, cont = 0, flag = 0, n = 0;
    for(k = 0; k < quadros; k++){
        vetorQuadros[k].distancia = 0;
    }
    for(i = 0; i < auxiliar.numeroPaginas; i++){
        if(cont < quadros){
            for(k = 0; k < n; k++){
                if(auxiliar.vetor[i].valor == vetorQuadros[k].valor){
                    flag = 1;
                    vetorQuadros[k].distancia = 0;
                }
                else{
                    vetorQuadros[k].distancia++;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                vetorQuadros[cont].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
                cont++;
                n++;
            }
        }
        else{
            for(k = 0; k < quadros; k++){
                if(auxiliar.vetor[i].valor == vetorQuadros[k].valor){
                    flag = 1;
                    vetorQuadros[k].distancia = 0;
                }
                else{
                    vetorQuadros[k].distancia++;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                int d = 0;
                for(k = 0; k < quadros; k++){
                    if(vetorQuadros[k].distancia == 0){
                        j = k;
                        break;
                    }
                    else if(d < vetorQuadros[k].distancia){
                        d = vetorQuadros[k].distancia;
                        j = k;
                    }
                }
                vetorQuadros[j].distancia = 0;
                vetorQuadros[j].valor = auxiliar.vetor[i].valor;
                numeroFaltas++;
            }
        }
    }
    free(vetorQuadros);
    return numeroFaltas;
}
