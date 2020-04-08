typedef struct vetor{
    int valor;
    int distancia;
}TmoduloVetor;

typedef struct numero{
    int valor;
    int flag;
}TmoduloNumero;

typedef struct paginas{
    TmoduloNumero *vetor;
    int numeroPaginas;
}TmoduloPagina;

void contarPaginas(char *nomeArquivo, int *numero);
void lerArquivo(char *nomeArquivo, TmoduloPagina *auxiliar, int *quadros, int numero);
int FIFO(TmoduloPagina auxiliar, int quadros);
void procuraOTM(TmoduloPagina auxiliar, TmoduloVetor *vetor, int quadros, int x);
int OTM(TmoduloPagina auxiliar, int quadros);
int LRU(TmoduloPagina auxiliar, int quadros);
