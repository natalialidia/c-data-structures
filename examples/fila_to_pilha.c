#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

typedef struct pilha{
	NO *inicio;
	int tam;
	
}PILHA;

typedef struct fila{
	NO *inicio;
	NO *fim;
	int tam;
	
}FILA;

PILHA * constructor(PILHA * pilha){
	pilha = (PILHA*) malloc (sizeof(PILHA));
	pilha->inicio = NULL;
	pilha->tam = 0;
	return pilha;
}

FILA * constructor_fila(FILA * fila){
	fila = (FILA*) malloc (sizeof(fila));
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->tam = 0;
	return fila;
}

void adicionar(int valor, PILHA * pilha){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->prox = pilha->inicio;
    pilha->inicio = novo;
    pilha->tam++;
}


void imprimir(NO * no){
	printf("\n%d\n", no->valor);
	if(no->prox != NULL){
		imprimir(no->prox);
	}
}


char remover(PILHA * pilha){
	int retorno = pilha->inicio->valor;
    NO* lixo = pilha->inicio;
    pilha->inicio = pilha->inicio->prox;
    free(lixo);
    pilha->tam--;
    return retorno;
    
}

void adicionar_fila(int valor, FILA * fila){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if(fila->fim == NULL){
    	fila->fim = novo;
    	fila->inicio = novo;
	}else{
		fila->fim->prox = novo;
    	fila->fim = novo;
	}
    fila->tam++;
}

int remover_fila(FILA * fila){
	NO* lixo = fila->inicio;
    fila->inicio = fila->inicio->prox;
    return lixo->valor;
    free(lixo);
}

void filaToPilha(FILA * fila1, PILHA * pilha){
	
	if(fila1->inicio != NULL){
		adicionar(remover_fila(fila1),pilha);
		filaToPilha(fila1, pilha);
	}
	
}

int menor(NO * no){
	
	if(no->prox != NULL){
		if(no->valor > menor(no->prox)){
			return menor(no->prox);
		}else{
			return no->valor;
		}
	}else{
		return no->valor;
	}
	
}


int maior(NO * no){
	
	if(no->prox != NULL){
		if(no->valor > maior(no->prox)){
			return no->valor;
		}else{
			return maior(no->prox);
		}
	}else{
		return no->valor;
	}
	
}

int main(){
	
	PILHA * p;
	p = constructor(p);
	FILA * fila1;
	fila1 = constructor_fila(fila1);
	FILA * fila2;
	fila2 = constructor_fila(fila2);
		
	adicionar_fila(10, fila1);
    adicionar_fila(4, fila1);
    adicionar_fila(5, fila1);
    adicionar_fila(36, fila1);
    
	
	printf("%d\n", menor(fila1->inicio));
	filaToPilha(fila1, p);
	printf("%d", maior(p->inicio));
	
	
//	imprimir(p->inicio);
	
	return 0;
}
