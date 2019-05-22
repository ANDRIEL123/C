#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int registro; // fixo 10
    char cod_empregado[10];
    char competencia[8];
    char cod_evento[4];
    int tipo_processo;
    char valor[9];
    char cod_empresa[10];
}Lancamento;

typedef struct{
    int registro; //fixo 11
    int dias_falta;
}Falta;

void verifica_arquivo(FILE *arquivo)
{
    if(arquivo == NULL){
    printf("Erro na abertura do arquivo!");
    exit(0);
    }
    else{
        printf("Arquivo aberto com sucesso!\n\n");
    }
}
void lancamentos_folha(FILE *arquivo, Lancamento *lancamento, int n)
{
    fclose(arquivo);
    fopen("lancamentos.txt","a");
    int i = 0, tam_cod_empregado = 0;
    printf("\n =========REGISTRO DE LANCAMENTOS========\n\n");
    for(i=1;i<=n;i++){
    printf("Digite o codigo do empregado %d:\n", i);
    fflush(stdin);
    scanf("%s",&lancamento[i].cod_empregado);
    tam_cod_empregado = strlen(lancamento[i].cod_empregado);
    printf("Digite a data, formato 'AAAAMM'\n");
    fflush(stdin);
    scanf("%s",&lancamento[i].competencia);
    printf("Digite o codigo do evento 'Rubrica'\n");
    fflush(stdin);
    scanf("%s",&lancamento[i].cod_evento);
    printf("Digite o codigo do tipo de processo '11 - folha mensal'\n");
    fflush(stdin);
    scanf("%d",&lancamento[i].tipo_processo);
    printf("Digite o valor Valor\n");
    fflush(stdin);
    scanf("%s",&lancamento[i].valor);
    printf("Digite o codigo da empresa\n");
    scanf("%s",&lancamento[i].cod_empresa);
    fflush(stdin);
    lancamento[i].registro = 10;
    fprintf(arquivo, "%d", lancamento[i].registro);
    fprintf(arquivo, "%010s", lancamento[i].cod_empregado);
    fprintf(arquivo, "%s", lancamento[i].competencia);
    fprintf(arquivo, "%04s", lancamento[i].cod_evento);
    fprintf(arquivo, "%d", lancamento[i].tipo_processo);
    fprintf(arquivo, "%09s", lancamento[i].valor);
    fprintf(arquivo, "%010s\n", lancamento[i].cod_empresa);

    }
}
void registro_faltas(FILE *arquivo, Falta *falta, int n){
    fclose(arquivo);
    fopen("lancamentos.txt","a");
    int i;
    printf("\n========REGISTRO DE FALTAS=========\n\n");
    for(i=1;i<=n;i++){
        printf("Digite a data da falta - FORMATO = 'AAAAMMDD'\n");
        scanf("%d",&falta[i].dias_falta);
        fflush(stdin);
        falta[i].registro = 11;
        fprintf(arquivo, "%d", falta[i].registro);
        fprintf(arquivo, "%d\n", falta[i].dias_falta);
    }
}

void analisa_arquivo(FILE *arquivo){
    fclose(arquivo);
    fopen("lancamentos.txt","r");
    char texto[200];
    printf("\n=============ANALISE DO ARQUIVO=============\n\n");
    while(fgets(texto, 100, arquivo) != NULL){
        printf("%s", texto);
    }
}

void menu(FILE *arquivo, Lancamento *lancamento, Falta *falta, int n){
    int opcao;

	do {
		printf("\n========Escolha a opcao abaixo:=========\n\n");
		printf("1 - REGISTRO DE LANCAMENTOS\n");
		printf("2 - REGISTRO DE DIAS DE FALTAS\n");
		printf("3 - ANALISE DO ARQUIVO\n");
		printf("4 - GRAVAR E SAIR\n");
		fflush(stdin);
		scanf("%d", &opcao);

		switch (opcao) {
				case 1 :
				lancamentos_folha(arquivo, lancamento, n);;

				break;
				case 2 :
				registro_faltas(arquivo, falta, n);

				break;
				case 3 :
                analisa_arquivo(arquivo);

                break;
				case 4 :
                printf("\n\nArquivo Salvo com sucesso!\n");
				printf("Saindo do programa\n...");
				fclose(arquivo);

				break;
				default :
				printf("Opcao invalida\n\n");
		}
	} while (opcao != 4);
}
int main()
{
    FILE *arquivo;
    arquivo = fopen("lancamentos.txt","a");
    verifica_arquivo(arquivo);
    Lancamento lancamento[50];
    Falta falta[50];
    menu(arquivo, lancamento, falta, 1);
}
