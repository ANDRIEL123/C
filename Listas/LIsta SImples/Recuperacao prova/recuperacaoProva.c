#include<stdio.h>
#include<stdlib.h>

typedef struct no {
  int dado;
  struct no * prox;
} Celula;

Celula *inserir(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox);

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
  int i;
  if(!l) printf("Lista vazia\n");

  for(i = 0, p = l; p; p = p -> prox, i++) {
     printf("%d -> %p -> %d\n", i, p, p->dado);
  }
}

Celula *abrirArquivoPopularFila(Celula *l) {
  FILE *procurador;
  char nomeArquivo[200];
  int dados;

  printf("Informe o nome do arquivo com os dados: \n");
  scanf("%s", nomeArquivo);
  fflush(stdin);

  procurador = fopen(nomeArquivo,"r");
  if(!procurador){
    printf("Arquivo nao encontrado ou invalido!\n");
    return l;
  }

  for(;1;) {
    fscanf(procurador,"%d",&dados);
    if (feof(procurador)) {
      break;
    }
    l = inserir(dados,l);
  }
  fclose(procurador);
  return l;
}

void *mostraRepetidos(Celula *l){
  Celula *p, *pControleGeral;
  int valorAnalisar;
  int qtdVezesAparece = 0;
  int guardaValor = 0;

  for(pControleGeral = l; pControleGeral; pControleGeral = pControleGeral -> prox){

    valorAnalisar = pControleGeral->dado;
    qtdVezesAparece = 0;

    for(p = l; p; p = p -> prox){
      if(p->dado == valorAnalisar) qtdVezesAparece++;
    }
      if (qtdVezesAparece > 1) {
        guardaValor = valorAnalisar;
        printf("%d\n", guardaValor);
      }
   }
}

int main() {
  Celula *lista = NULL;

  lista = abrirArquivoPopularFila(lista);
  exibir(lista);
  printf("Dados repetidos:\n");
  mostraRepetidos(lista);
}
