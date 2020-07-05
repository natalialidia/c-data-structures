#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no * prox;	
	struct no * ant;	
}NO;

typedef struct lista{
	NO * inicio;
	NO * fim;
	int tam;	
} LISTA;

void constructor(LISTA * lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tam = 0;
}

void adicionar(int valor, LISTA * lista){
	NO * novo = (NO*) malloc(sizeof(NO));
	novo->valor = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	if(lista->inicio==NULL){
		lista->inicio=novo;
		novo->prox = novo;
		novo->ant = novo;
		lista->fim = novo;
	}else{
		novo->ant = lista->inicio;
		novo->prox = lista->inicio->prox;
		lista->inicio->prox->ant = novo;
		lista->inicio->prox = novo;
	}
	lista->tam++;
	
}


int remover(int valor, LISTA * lista){	
	NO * lixo;
	NO * aux;
	int i;
	int retorno;
	
	if(lista->inicio != NULL){
		
		if(lista->inicio->valor == valor){
			lixo = lista->inicio;
			retorno = lixo->valor;
			lista->inicio->ant->prox = lista->inicio->prox;
			lista->inicio->prox->ant = lista->inicio->ant;
			lista->inicio = lista->inicio->prox;
			free(lixo);
			lista->tam--;	
		}else{
			aux = lista->inicio->prox;
			while(aux != lista->inicio){
				if(aux->valor == valor){
					lixo = aux;
					retorno = lixo->valor;
					aux->prox->ant = aux->ant;
					aux->ant->prox = aux->prox;
					free(lixo);
					lista->tam--;
					aux = lista->inicio; //Parar execução do while
				}else{
					aux = aux->prox;
				}
			}
			
		}
		
		return retorno;
		
	}
	
}

void imprimir(LISTA * lista){
	NO * aux = lista->inicio;
	int i;
	puts("\n|LISTA|\n");
	for(i=0;i<=lista->tam-1;i++){
		printf("%d   ", aux->valor);
		aux=aux->prox;
	}
}

int main(){
	
	LISTA * lista1 = (LISTA*) malloc(sizeof(LISTA));
	constructor(lista1);
	LISTA * lista2 = (LISTA*) malloc(sizeof(LISTA));
	constructor(lista2);
	
	adicionar(2, lista1);
	adicionar(4, lista1);
	adicionar(6, lista1);
	adicionar(7, lista1);
	adicionar(10, lista1);
	adicionar(20, lista1);
	imprimir(lista1);
	remover(20, lista1);
	imprimir(lista1);
	return 0;
}
