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

int main() {
  srand(time(NULL));
  int n = 3;
  int vetor[n];
  populaVetor(vetor, n);
  exibirVetor(vetor, n);
  return 1;
}
