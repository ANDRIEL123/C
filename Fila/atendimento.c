#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	long int cpf;
  char *nome;
	struct no *prox;
} Celula;

typedef struct {
  Celula *inicio;
  Celula *fim;
} Fila;

void inicializarFila(Fila *f) {
  f->inicio = NULL;
  f->fim = NULL;
}

void exibir(Fila *f) {
		Fila *aux;
		if(!f->inicio) {
			printf("\nFila vazia!\n\n");
		} else {
			for(aux->inicio = f->inicio; aux->inicio; aux->inicio = aux->inicio->prox){
	      printf("CPF: %ld\n", aux->inicio->cpf);
	    }
			printf("\n");
		}


}

void inserirFila(long int cpf, Fila *f) {
  Celula *novo = (Celula *)malloc(sizeof(Celula));
  novo->cpf = cpf;
  novo->prox = NULL;

  if(!f->fim){
    f->inicio = novo;
    f->fim = novo;

  }else{
    f->fim->prox = novo;
    f->fim = novo;
  }

}

int atenderFila(Fila *f) {
	Celula *lixo;
	int dadoRemovido = -1;

	if (!f->inicio) {
		printf("Fila vazia\n");
	} else {
		lixo = f->inicio;
		f->inicio = f->inicio->prox;
		dadoRemovido = lixo->cpf;
		free(lixo);
		if (!f->inicio) f->fim = NULL;
	}
	return dadoRemovido;
}

void menu(Fila *filaNormal, Fila *filaPrioritaria){
  int opcao = 0, contador = 0;
	long int recebe = 0;
  long int cpfN = 0, cpfP = 0;

  do {
    printf("1 - Gerar ficha normal\n");
    printf("2 - Gerar ficha prioritária\n");
    printf("3 - Atender\n");
    printf("4 - Exibir filas\n");
    printf("0 - Sair\n");
    scanf("%d",&opcao);

    switch (opcao) {
      case 1:
				printf("\n====GERACAO DE FICHA NORMAL==\n\n");
        printf("Digite o CPF:\n");
        scanf("%ld",&cpfN);
        inserirFila(cpfN, filaNormal);
      break;
			case 2:
				printf("\n====GERACAO DE FICHA PRIORITARIA==\n\n");
				printf("Digite o CPF:\n");
				scanf("%ld",&cpfP);
				inserirFila(cpfP, filaPrioritaria);
			break;

			case 3:
				printf("\n====AREA DE ATENDIMENTO===\n\n");

				if(!filaPrioritaria->inicio && !filaNormal->inicio){
					printf("Filas vazias\n\n");
					break;
				}

				if(contador == 3 || !filaNormal->inicio) {
					recebe = atenderFila(filaPrioritaria);

					printf("===PACIENTE DA FILA PRIORITARIA COM CPF %ld ATENDIDO!\n",
					recebe);
					contador = 0;
				} else {
					recebe = atenderFila(filaNormal);
					printf("===PACIENTE DA FILA NORMAL COM CPF %ld ATENDIDO!\n",
					recebe);
				}
				contador ++;
			break;

			case 4:
				printf("\nFila prioritária\n");
      	exibir(filaPrioritaria);
				printf("Fila normal\n");
				exibir(filaNormal);
      break;
    }


  } while(opcao != 0);

}

int main() {
  Fila filaNormal;
	Fila filaPrioritaria;

  inicializarFila(&filaNormal);
	inicializarFila(&filaPrioritaria);
  menu(&filaNormal, &filaPrioritaria);


}
