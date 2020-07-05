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

void adicionar(int valor, int pos, LISTA * lista){
	NO * novo = (NO*) malloc(sizeof(NO));
	novo->valor = valor;
	novo->prox = NULL;
	novo->ant = NULL;
	if(lista->inicio==NULL){
		lista->inicio=novo;
		lista->fim = novo;
	}else if(pos==0){
		novo->prox = lista->inicio;
		lista->inicio->ant = novo;
		lista->inicio = novo;
	}else if(pos==lista->tam){
		lista->fim->prox = novo;
		novo->ant = lista->fim;
		lista->fim = novo;
	}else{
		NO * aux = lista->inicio;
		int i;
		for(i=0; i<pos; i++){
			aux = aux->prox;
		}
		novo->prox = aux;
		novo->ant = aux->ant;
		aux->ant->prox = novo;
		aux->ant = novo;
	}
	lista->tam++;
	
}


int remover(int pos, LISTA * lista){	
	NO * lixo;
	NO * aux;
	int i;
	int retorno;
	if(pos>=0 && pos<lista->tam){
		
		if(lista->tam == 1 && pos == 0){ //lista tem 1 elemento
	        lixo = lista->inicio;
	        lista->inicio = NULL;
	        lista->fim = NULL;
	    }else if(pos==0){
			lixo = lista->inicio;
			lista->inicio = lista->inicio->prox;
			lista->inicio->ant = NULL;
			
		}else if(pos == lista->tam-1){
			
			lixo = lista->fim;
			lista->fim->ant->prox = NULL;
			lista->fim = lista->fim->ant;
			
		}else{
			aux = lista->inicio;
			
			for(i=0;i<pos;i++){
				aux = aux->prox;
			}
			
			lixo = aux;
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			
		}
		
		retorno = lixo->valor;
		free(lixo);
		
	}
	lista->tam--;
	return retorno;
	
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
	
	adicionar(2,0, lista1);
	adicionar(4,1, lista1);
	adicionar(7,2, lista1);
	adicionar(-7,3, lista1);
	adicionar(10,2, lista1);
	adicionar(20,1, lista1);
	imprimir(lista1);
	remover(0, lista1);
	remover(2, lista1);
	remover(4, lista1);
	imprimir(lista1);
	return 0;
}
