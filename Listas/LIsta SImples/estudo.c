#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct no {
  int dado;
  struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor < p->dado) break;
    }
    printf("%p -> %p",p,l);
    if (p == l) { //inicio
        novo->prox = l;
        return l;
    }
    pR->prox = novo; //ultimo
    if (p) {
        novo->prox = p; //meio
    }
    return l;
}

void exibir(Celula *l){
  Celula *p;
  for(p = l; p; p = p->prox){
    printf("%d\n", p->dado);
  }
}

int main(){
  Celula *lista = NULL;
  srand(time(NULL));
  int i = 3;

  for (; i > 0; i--) {
      lista = inserir(rand() % 100, lista);
  }

  exibir(lista);
}
