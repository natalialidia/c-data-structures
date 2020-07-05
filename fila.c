#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


void adicionar(int valor){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if(fim == NULL){
    	fim = novo;
    	inicio = novo;
	}else{
		fim->prox = novo;
    	fim = novo;
	}
    tam++;
}


void imprimir(){
    NO *aux = inicio;
    int i;
    printf("Imprimindo a fila :D\n");
    for(i=0; i< tam; i++){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int remover(){
	NO* lixo = inicio;
    inicio = inicio->prox;
    tam--;
    free(lixo);
}


int main(){
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(4);
    adicionar(4);
    adicionar(4);
    imprimir();
    remover();
    remover();
    remover();
    imprimir();
    return 0;
}
