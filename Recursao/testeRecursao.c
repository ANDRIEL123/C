#include <stdio.h>
#include <stdlib.h>

int recursao(int valor) {
  if(valor == 0) printf("%d\n", valor);
  else {
  recursao(valor - 1);
  printf("%d\n", valor);
  }
}

int main() {
  recursao(10);
}
