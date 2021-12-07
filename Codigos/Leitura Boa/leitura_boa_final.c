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

char leitura_boa(char *formato,void *dados,char num,char tam_buffer)
{

	char *erro_leitura,teclado_entrada[tam_buffer],leitura_scan[3]={'%',0,0},i;
	//Declara ponteiro para os erros e buffer para o Teclado
	erro_leitura=fgets(teclado_entrada,tam_buffer,stdin);					//Le teclado e atribue um ponteiro como retorno para verificar erros
	limpa_buffer();													//Limpa o Buffer para a possivel proxima leitura
	if(erro_leitura!=NULL || (teclado_entrada[0]!='\n'
	&& strlen(teclado_entrada)!=1) )	//Houve erro de leitura? o Usuario digitou "enter"?
	{
		erro_leitura=(char *)malloc(1*sizeof(char));				//Se não houve, aloque uma char para o ponteiro
		for(;num>0;){
			leitura_scan[1]=*(formato+1);

			switch(leitura_scan[1]){
				case 'd':
					*erro_leitura=(char)sscanf(teclado_entrada,"%d",(int*)dados );
					dados = dados+sizeof(int);
					break;
				case 'f':
					*erro_leitura=(char)sscanf(teclado_entrada,leitura_scan,(float*)dados);
					dados = dados+sizeof(float);
					break;
				case '*':	//Ignorar
					break;
				default:
					*erro_leitura=(char)sscanf(teclado_entrada,leitura_scan,(char*)dados);
			}

			if(*erro_leitura==-1 || *erro_leitura==0){
				free(erro_leitura);
				return 1;
			}

			for(i=0;i<strlen(teclado_entrada);i++)if(teclado_entrada[i]!=' ')break;

			switch(leitura_scan[1]){
				case 'c':
					teclado_entrada[i]=' ';
					break;

				case 's':
					do{
						teclado_entrada[i]=' ';
						i++;
					}while(teclado_entrada[i]!=' ');
					break;

				case '*':
					teclado_entrada[i]=' '; //Ignorar
					break;

				default:
					do{
						teclado_entrada[i]=' ';
						i++;
					}while(!(teclado_entrada[i]==' ' || teclado_entrada[i]>57 || teclado_entrada[i]=='\n') );
			}//END SWITCH (leitura_scan[1])
			formato+=2;
			num--;
		}//END for(;num>0;)
		free(erro_leitura);
		return 0;
	}//END IF
	return 1;
}//END leitura_boa

int main()
{
	int ano,erros,tupac;
	void *vetor_ptr[2]={&ano,&erros};
	tupac=leitura_boa("%d%d",*vetor_ptr,2,20);
	if(tupac)printf("Erros");
	else printf("OK");
    return 0;
}
