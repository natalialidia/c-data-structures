#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

typedef struct pilha{
	NO *inicio;
	int tam;
} PILHA;

PILHA * constructor(PILHA * pilha){
	pilha = (PILHA*) malloc (sizeof(PILHA));
	pilha->inicio = NULL;
	pilha->tam = 0;
	return pilha;
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

int remover(PILHA * pilha){
	
	int retorno = pilha->inicio->valor;
    NO* lixo = pilha->inicio;
    pilha->inicio = pilha->inicio->prox;
    free(lixo);
    pilha->tam--;
    return retorno;
    
}

void empilhadeira (PILHA *A, PILHA *B, PILHA *C, int caixa){
	
	if(A->inicio != NULL){
		if(A->inicio->valor == 7){
			adicionar(caixa, A);
		}else if(A->inicio->valor == 5){
			if(caixa == 7){
				adicionar(remover(A), B);
				empilhadeira(A, B, C, caixa);
				adicionar(remover(B), A);
			}else{
				adicionar(caixa, A);
			}
		}else if(A->inicio->valor == 3){
			if(caixa == 5 || caixa == 7){
				adicionar(remover(A), C);
				empilhadeira(A, B, C, caixa);
				adicionar(remover(C), A);
			}else{
				adicionar(caixa,A);
			}
		}
	}else{
		adicionar(caixa,A);
	}
	
}

int maior(NO * no){
	
	if(no->prox != NULL){
		if(no->valor < maior(no->prox)){
			return no->prox->valor;
		}
	}
	
	return no->valor;
	
}


int main(){
	
	PILHA * A;
	A = constructor(A);
	PILHA * B;
	B = constructor(B);
	PILHA * C;
	C = constructor(C);
	
	empilhadeira(A, B, C, 3);
	empilhadeira(A, B, C, 3);
	empilhadeira(A, B, C, 5);
	empilhadeira(A, B, C, 7);
	empilhadeira(A, B, C, 3);
	empilhadeira(A, B, C, 7);
	
	imprimir(A->inicio);
	
    return 0;
}
