#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO *inicio = NULL;
int tam = 0;


void adicionar(int valor){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->prox = inicio;
    inicio = novo;
    tam++;
}


void imprimir(){
    NO *aux = inicio;
    int i;
    printf("\nImprimindo a pilha :D\n");
    for(i=0; i< tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int remover(){
	
	int retorno = inicio->valor;
    NO* lixo = inicio;
    inicio = inicio->prox;
    free(lixo);
    tam--;
    return retorno;
    
}


int main(){
    adicionar(20);
    adicionar(30);
    adicionar(4);
    adicionar(432);
    imprimir();
    remover();
    imprimir();
    return 0;
}

