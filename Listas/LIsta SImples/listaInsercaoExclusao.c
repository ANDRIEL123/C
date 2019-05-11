#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

void exibir(Celula *l) {
    Celula *p;
    int i;
    for (i = 0,p = l; p; p = p->prox, i++) {
        printf("%d -> %p -> %d\n", i, p, p->dado);
    }
}

Celula *inserir(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor < p->dado) break;
    }

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

Celula *excluir(int valor, Celula *l) {
    Celula *pR, *p;
    if (!l) return l;
    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor == p->dado) break;
    }
    if (!p) return l; //nao localizado
    if (p == l) { //localizado no inicio
        l = l->prox;
        free(p);
        return l;
    }
    if (!p->prox) { //encontrado na ultima posicao
        free(p);
        pR->prox = NULL;
        return l;
    }
    pR->prox = p->prox;
    free(p);

    return l;
}

int pesquisaMaior(Celula *l)
{
    int maior = l->dado;
    while(l != NULL)
    {
        if(l->dado > maior)
            maior = l->dado;
            l= l->prox;
    }
    printf("Maior: %d\n", maior);
    return maior;
}
int pesquisaMenor(Celula *l)
{
    int menor = l->dado;
    while(l != NULL)
    {
        if(l->dado < menor)
            menor = l->dado;
            l = l->prox;
    }
    printf("Menor: %d\n", menor);
    return menor;
}


int main() {
    Celula *lista = NULL;
    int numero;
    int maior, menor;
    srand(time(NULL));
    int i = rand() % 20;

    for (; i > 0; i--) {
        lista = inserir(rand() % 100, lista);
    }
    exibir(lista);
    maior = pesquisaMaior(lista);
    lista = excluir(maior, lista);
    menor = pesquisaMenor(lista);
    lista = excluir(menor, lista);
    printf("Lista sem o menor e o maior:\n");
    exibir(lista);
    return 1;
}
