#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char input[100];
	char data[1000];
	char option;

	printf("O que fazer com o arquivo? (w = escrever; r = ler): ");
	scanf(" %c", &option);
	getchar();

	if (option == 'r')
	{
		printf("Documento a ser lido: ");

		fgets(input, sizeof input, stdin);
		input[strcspn(input, "\n")] = '\0';

		fptr = fopen(input, "r");

		if (fptr == NULL)
		{
			printf("Arquivo não foi aberto.\n");
			return 0;
		}
		
		char result[10000];
		while(fgets(result, sizeof result, fptr) != NULL)
		{
			printf("%s", result);
		}
		fclose(fptr);
	}
	else if (option == 'w')
	{
		printf("Nome do documento: ");

		fgets(input, sizeof input, stdin);
		input[strcspn(input, "\n")] = '\0';

		fptr = fopen(input, "w");

		if (fptr == NULL)
		{
			perror("Arquivo não foi aberto.\n");
			return 1;
		}

		printf("Conteúdo:\n");
		
		if (fgets(data, sizeof data, stdin) != NULL)
		{
			fputs(data, fptr);
		}

		fclose(fptr);
	}
	else
	{
		printf("Opção inválida.");
		return 1;
	}

	return 0;
}
