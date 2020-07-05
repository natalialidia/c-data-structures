#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no * esq;
	struct no * dir;
} NO;

NO * raiz = NULL;

NO * busca(NO * no, int chave){
	
	if(no == NULL){
		return no;
	}
	
	if(chave < no->chave){
		if(no->esq == NULL){
			return no;
		};
		return busca(no->esq,chave);
	}
	
	if(chave > no->chave){
		if(no->dir == NULL){
			return no;
		};
		return busca(no->dir,chave);
	}
	
}

void inserir(int chave){
	
	NO * novo = (NO*) malloc(sizeof(NO));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->chave = chave;
	
	if(raiz == NULL){
		raiz = novo;
	}else{
		NO * aux = busca(raiz, chave);
		if(chave > aux->chave){
			aux->dir = novo;
		}else{
			aux->esq = novo;
		}
	}
}

NO * remover(NO * no, int x){
	
	if(no == NULL){
		return NULL;
	}else if(no->chave > x){
		no->esq = remover(no->esq, x);
		return no;
	}else if(no->chave < x ){
		no->dir = remover(no->dir, x);
		return no;
	}else{
		if(no->esq == NULL && no->dir == NULL){
			free(no);
			return NULL;
		}else if(no->esq == NULL){
			NO * aux = no;
			no = no->dir;
			free(aux);
		}else if(no->dir == NULL){
			NO * aux = no;
			no = no->esq;
			free(aux);
		}else{
			NO * aux = no->esq;
			while(aux->dir != NULL){
				aux = aux->dir;
			}
			no->chave = aux->chave;
			aux->chave = x;
			no->esq = remover(no->esq, x);
		}
	}
	return no;
}

void in_ordem(NO * no){
	if(no != NULL){
		in_ordem(no->esq);
		printf("%d  ", no->chave);
		in_ordem(no->dir);
	}
}


int main(){
	
	inserir(4);
	inserir(7);
	inserir(8);
	inserir(3);
	inserir(2);
	inserir(6);
	
	in_ordem(raiz);
	
	printf("\n");
	remover(raiz, 4);
	
	in_ordem(raiz);
	
	return 0;
}

