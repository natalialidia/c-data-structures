#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no * prox;	
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
	if(lista->inicio==NULL){
		lista->inicio=novo;
		lista->fim = novo;
	}else if(pos==0){
		novo->prox = lista->inicio;
		lista->inicio = novo;
	}else if(pos==lista->tam){
		lista->fim->prox = novo;
		lista->fim = novo;
	}else{
		NO * aux = lista->inicio;
		int i;
		for(i=0; i<pos-1; i++){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	lista->tam++;
	
}


int remover(int pos, LISTA * lista){	
	NO * lixo;
	NO * aux;
	int i;
	int retorno;
	if(pos>=0 && pos<lista->tam){
		
		if(pos==0){
			lixo = lista->inicio;
			lista->inicio = lista->inicio->prox;
			
		}else if(pos == lista->tam-1){
			
			aux = lista->inicio;
			
			for(i=0;i<lista->tam-2;i++){
				aux = aux->prox;
			}
			
			lixo = aux->prox;
			aux->prox = NULL;
			
		}else{
			aux = lista->inicio;
			
			for(i=0;i<pos-1;i++){
				aux = aux->prox;
			}
			
			lixo = aux->prox;
			aux->prox = aux->prox->prox;
			
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

int nao_negativos(NO * inicio){
	
	int retorno = 1;
	
	if(inicio != NULL){
		if(inicio->valor >= 0){
			retorno = nao_negativos(inicio->prox);
		}else{
			retorno = 0;
		}
	}
	
	return retorno;
	
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
