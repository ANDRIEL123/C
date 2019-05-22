#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int registro; // fixo 10
    int cod_empregado;
    char competencia[8];
    int cod_evento;
    int tipo_processo;
    float valor;
    int cod_empresa;

}Lancamento;

typedef struct{
    int registro; //fixo 11
    char dias_falta[8];
}Falta;

void verifica_arquivo(FILE *arquivo)
{
    if(arquivo == NULL){
    printf("Erro na abertura do arquivo!");
    }
    else{
        printf("Arquivo aberto com sucesso!\n\n");
    }
}

void lancamentos_folha(FILE *arquivo, Lancamento *lancamento, int n)
{
    int i = 0;
    printf("\n =========REGISTRO DE LANCAMENTOS========\n\n");
    for(i=1;i<=n;i++){
    printf("Digite o codigo do empregado %d:\n", i);
    fflush(stdin);
    scanf("%d",&lancamento[i].cod_empregado);
    printf("Digite a data, formato 'AAAAMM'\n");
    fflush(stdin);
    scanf("%s",&lancamento[i].competencia);
    printf("Digite o codigo do evento 'Rubrica'\n");
    fflush(stdin);
    scanf("%d",&lancamento[i].cod_evento);
    printf("Digite o codigo do tipo de processo '11 - folha mensal'\n");
    fflush(stdin);
    scanf("%d",&lancamento[i].tipo_processo);
    printf("Digite o valor Valor\n");
    fflush(stdin);
    scanf("%f",&lancamento[i].valor);
    printf("Digite o codigo da empresa\n");
    scanf("%d",&lancamento[i].cod_empresa);
    fflush(stdin);
    lancamento[i].registro = 10;
    fprintf(arquivo, "%d", lancamento[i].registro);
    fprintf(arquivo, "%09d", lancamento[i].cod_empregado);
    fprintf(arquivo, "%s", lancamento[i].competencia);
    fprintf(arquivo, "%02d", lancamento[i].cod_evento);
    fprintf(arquivo, "%07d", lancamento[i].tipo_processo);
    fprintf(arquivo, "%06d", lancamento[i].valor);
    fprintf(arquivo, "%07d\n", lancamento[i].cod_empresa);

    }
}

void registro_faltas(FILE *arquivo, Falta *falta, int n){
    int i;
    printf("\n========REGISTRO DE FALTAS=========\n\n");
    for(i=1;i<=n;i++){
        printf("Digite a data da falta - FORMATO = 'AAAAMMDD'\n");
        scanf("%d",&falta[i].dias_falta);
        fflush(stdin);
        falta[i].registro = 11;
        fprintf(arquivo, "%d", falta[i].registro);
        fprintf(arquivo, "%s\n", falta[i].dias_falta);
    }

}

int main()
{
    FILE *arquivo;
    arquivo = fopen("teste.txt","w");
    verifica_arquivo(arquivo);
    int num;
    printf("Digite o numero de lancamentos que deseja realizar\n");
    scanf("%d",&num);
    Lancamento lancamento[num];
    Falta falta[num];
    lancamentos_folha(arquivo, lancamento, num);
    registro_faltas(arquivo, falta, num);

}
