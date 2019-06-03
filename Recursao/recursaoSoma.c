#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void populaVetor(int *v, int n) {
  if (n > 0) {
    v[n - 1] = rand() % 100;
    populaVetor(v, n - 1);
  }
}

void exibirVetor(int *v, int n) {
  if (n > 0) {
    exibirVetor(v, n - 1);
    printf("%d\n", v[n - 1]);
  }
}

int somaVetorPares(int *v, int n) {
  int soma = 0;
  if (n > 0 && v[n - 1] % 2 == 0) {
    soma = somaVetorPares(v, n - 1);
    return v[n - 1] + soma;
  }
  return 0;
}

int somaVetorImpar(int *v, int n) {
  int soma = 0;
  if (n > 0 && v[n - 1] % 2 == 1) {

    soma = somaVetorImpar(v, n - 1);
    return v[n - 1] + soma;
  }
  return 0;
}



int main() {
  int somaPar = 0;
  int somaImpar = 0;
  srand(time(NULL));
  int n = 10;
  int vetor[n];
  populaVetor(vetor, n);
  exibirVetor(vetor, n);
  somaPar = somaVetorPares(vetor, n);
  printf("A soma dos pares: %d\n", somaPar);
  somaImpar = somaVetorImpar(vetor, n);
  printf("A soma dos impares: %d\n", somaImpar);

  return 1;
}
