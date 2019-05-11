#include<stdio.h>
#include<stdlib.h>

/*//PERCURSO SIMPLES
for(p = l; p; p -> prox != l; p = p -> prox){
  //instruções -> Exibir/Contar/Pesquisar
}*/

typedef struct no {
    int dado;
    struct no *prox;
}Celula; //USADO PARA SIMPLES OU CIRCULAR


/*VERIFICA SE A LISTA É SIMPLES OU CIRCULAR

Celular *verificaSimplesCircular(Celula *l){
  Celula *p;
  if(!l) return 0;
  for(p = l; 1; p = p -> prox){
    if(!p -> prox) return 1; //VERIFICA SE É SIMPLES
    if(p -> prox == l) return 2; //VERIFICA SE É CIRCULAR
  }
}

Celula *podaCircular(Celula *l){
  Celula *p, *pR, *pR2;
  if(!l) return l;
  pR = l;
  if(l->prox == l){
    free(p);
    return null;
  }
  l = l -> prox;
  for(p = l; pR2 = pR; p->prox != pR; pR2 = p; p = p -> prox);
  pr2 -> prox = l;
  free(p);
  free(pR);
  return l;
}

//-========================DESTRUIR SIMPLES===========================
Celula *destruir(Celula *l){
   Celula *p;
   if(!l) return l;
   for(p=l; l = l->prox; l; p = l; l = l -> prox){
     free(p);
   }
   free(p);
}

int main(){

}
*/
//=======================DESTRUIR CIRCULAR==========================
Celula *destruirCircular(Celula *l){
  Celula *p, *pR;
  if(!l) return l; //TESTE VEIFICADO SE O L EXISTE
  pR = l; //backup do fim do primeiro elemento
  for(p = l, l = l -> prox; l -> prox != pR; p = l, l = l -> prox){
    free(p);
  }
  free(p);
  free(l);
  return NULL;
}
