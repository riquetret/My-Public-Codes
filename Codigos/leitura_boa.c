#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

void limpa_buffer() {
    int caracter=0;
    do {
    caracter = fgetc(stdin);
    } while (caracter != '\n' && caracter!=EOF);
    if(caracter==EOF)clearerr(stdin);
}

int main()
{

	int ano;
	printf("tamanho do char é: %dBytes\n",sizeof(char));
	printf("Digite um mes em numero: ");

	char *erro_leitura,teclado_entrada[3];
	//Declara ponteiro para os erros e buffer para o Teclado
	while(1)
	{
		erro_leitura=fgets(teclado_entrada,3,stdin);					//Le teclado e atribue um ponteiro como retorno para verificar erros
		limpa_buffer();													//Limpa o Buffer para a possivel proxima leitura
		if(erro_leitura!=NULL || (teclado_entrada[0]!='\n'
									&& strlen(teclado_entrada)!=1) )	//Houve erro de leitura? o Usuario digitou "enter"?
		{
			erro_leitura=(char *)malloc(1*sizeof(char));				//Se não houve, aloque uma char para o ponteiro
			*erro_leitura=(char)sscanf(teclado_entrada,"%d",&ano);		//Atribua

			if(*erro_leitura!=-1 && *erro_leitura!=0 && (ano>0 && ano<13))
			{
				free(erro_leitura);
				break;
			}
			free(erro_leitura);
		}
		printf("\n Erro digite novamente: ");
	}//End While(1)

	printf("SAIU");

    return 0;
}
