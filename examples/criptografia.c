#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char expressao[100];

typedef struct no{
    char letra;
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

void adicionar(char letra, PILHA * pilha){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->letra = letra;
    novo->prox = NULL;
    novo->prox = pilha->inicio;
    pilha->inicio = novo;
    pilha->tam++;
}


void imprimir(FILA * fila){
    NO *aux = fila->inicio;
    int i;
    printf("\nResultado:\n");
    for(i=0; i< fila->tam; i++){
        printf("%c", aux->letra);
        aux = aux->prox;
    }
}

char remover(PILHA * pilha){
	int retorno = pilha->inicio->letra;
    NO* lixo = pilha->inicio;
    pilha->inicio = pilha->inicio->prox;
    free(lixo);
    pilha->tam--;
    return retorno;
    
}

void criptografar(char letra, PILHA * crip, PILHA * aux){
	if(aux->inicio != NULL){
		adicionar_fila(remover(aux), crip);
		criptografar(letra, crip, aux);
	}else{
		adicionar_fila(letra, crip);
	}
}

void adicionar_fila(char letra, FILA * fila){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->letra = letra;
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
    free(lixo);
}

void percorrer(PILHA * aux, FILA * crip){
	int i;
	for(i=0;i<strlen(expressao);i++){
		if(expressao[i] != 'a' && expressao[i] != 'b' && expressao[i] != 'c' && expressao[i] != 'd' && expressao[i] != 'e'){
			adicionar(expressao[i], aux);
		}else{
			criptografar(expressao[i], crip, aux);
		}
	}
	
}


int main(){
	
	printf("Digite a expressao:\n");
	gets(expressao);
	
	PILHA * aux;
	aux = constructor(aux);
	FILA * criptografada;
	criptografada = constructor_fila(criptografada);
	
	percorrer(aux, criptografada);
		
	imprimir(criptografada);
	
	return 0;
}
