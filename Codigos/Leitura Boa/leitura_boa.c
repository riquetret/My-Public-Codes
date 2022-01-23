#include <stdio.h>
#include <string.h>

int leitura_boa(void *ptr,int tam,char tipo){
	int k=1;
	int erro=0;
	switch (tipo)
	{
	case 'i':											//Vamos ler inteiros
		for(k=0;k<tam;k++){								//K para iterar num possivel vetor
			printf("\nDigite a informacao %d: ",k+1);	//Pede informação
            while(scanf("%d",((int*)ptr)[k])!=1){				//Se o scanf encontrar algo errado peça novamente (Scanf retornar EOF ou 0)
				printf("\n Erro digite novamente: ");	//Exibe erro para usuário
				limpa_buffer();							//Limpa lixo do teclado
			}limpa_buffer();							//Limpa lixo do teclado
		}//END FOR(k=0;k<tam;k++)
		break;
	case 'f':											//Vamos ler floats
		for(k=0;k<tam;k++){								//K para iterar num possivel vetor
			printf("\nDigite a informacao %d: ",k+1);	//Pede informação
			while(scanf("%f",((float*)ptr)[k])!=1){				//Se o scanf encontrar algo errado peça novamente (Scanf retornar EOF ou 0)
				printf("\n Erro digite novamente: ");	//Exibe erro para usuário
				limpa_buffer();							//Limpa lixo do teclado
			}limpa_buffer();							//Limpa lixo do teclado
		}//END FOR(k=0;k<tam;k++)
		break;
	case 'd':											//Vamos ler doubles
		for(k=0;k<tam;k++){								//K para iterar num possivel vetor
			printf("\nDigite a informacao %d: ",k+1);	//Pede informação
			while(scanf("%lf",((double*)ptr)[k])!=1){				//Se o scanf encontrar algo errado peça novamente (Scanf retornar EOF ou 0)
				printf("\n Erro digite novamente: ");	//Exibe erro para usuário
				limpa_buffer();							//Limpa lixo do teclado
			}limpa_buffer();							//Limpa lixo do teclado
		}//END FOR(k=0;k<tam;k++)
		break;
	case 's':											//Vamos ler uma string
		printf("\nDigite a seguir: ");					//Pede ao usuário o texto
		while(fgets((char*)ptr,tam,stdin)==NULL){				//Se nao consegui ler temos NULL
			printf("\nErro Digite Novamente");			//Exibe erro para usuário
			limpa_buffer();								//Limpa lixo do teclado
		}limpa_buffer();								//Limpa lixo do teclado
        if(*(((char*)ptr)+tam-1)=='\n')*((((char*)ptr)+strcspn((char*)ptr, "\n")))=0;  //Retira possível \n do vetor
		break;
	default:											//Vamos ler um char
		for(k=0;k<tam;k++){								//K para iterar num possivel vetor
			printf("\nDigite a informacao %d: ",k+1);	//Pede informação
			while(scanf("%c",((char*)ptr)[k])!=1){				//Se o scanf encontrar algo errado peça novamente (Scanf retornar EOF ou 0)
				printf("\n Erro digite novamente: ");	//Exibe erro para usuário
				limpa_buffer();							//Limpa lixo do teclado
			}limpa_buffer();							//Limpa lixo do teclado
		}//END FOR(k=0;k<tam;k++)
			break;
	}
	return k;
}

/*
Função: Limpa_Buffer
Autor: Baseado em outras pessoas, modificada por Henrique.
Entradas:Stdin
Saídas: Nenhuma
Retorno: Nenhum

Objetivo: Consumir caracteres
adicionais presentes no stdin.
Se a função encontrar um EOF ela
Reseta o stdin para futuras leituras
*/
void limpa_buffer() {
    char caracter=0;									//Declara char para a leitura
    do {
    caracter = fgetc(stdin);							//Le caracter por caracter ate "zerar" stdin
    } while (caracter != '\n' && caracter!=EOF);		//Se foi encontrado uma quebra de linha ou um erro saia
    if(caracter==EOF)clearerr(stdin);					//Se foi encontrado um EOF, resete stdin
}
