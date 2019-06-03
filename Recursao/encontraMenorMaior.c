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

int encontraMenor(int *v, int n) {
  if(n > 1) {
    int decima = encontraMenor(v, n - 1);
    if(v[n - 1] < decima) return v[n - 1];
    return decima;
  }
  return v[n - 1];
}

int encontraMaior(int *v, int n) {
  if(n > 1) {
    int decima = encontraMaior(v, n - 1);
    if(v[n - 1] > decima) return v[n - 1];
    return decima;
  }
  return v[n - 1];
}

int main() {
  int maior = 0, menor = 0;
  srand(time(NULL));
  int n = 3;
  int vetor[n];
  populaVetor(vetor, n);
  exibirVetor(vetor, n);
  menor = encontraMenor(vetor, n);
  printf("Menor %d\n", menor);
  maior = encontraMaior(vetor, n);
  printf("Maior %d\n", maior);
  return 1;
}
