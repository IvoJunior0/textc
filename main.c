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

	printf("O que fazer com o arquivo? (w = escrever; r = ler)");
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
			fclose(fptr);
			return 0;
		}
		
		char result[10000];
		while(fgets(result, 10000, fptr))
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
			printf("Arquivo não foi aberto.\n");
			fclose(fptr);
			return 0;
		}

		printf("Conteúdo:\n");
		data[0] = '\0';
		size_t pos = 0;
		while (pos < sizeof(data) - 1 && fgets(data + pos, sizeof(data) - pos, fptr) != NULL) {
    			pos = strlen(data);
		}

		fprintf(fptr, data);
	}
	else
	{
		printf("Opção inválida.");
		return 0;
	}
	fclose(fptr);
	return 0;
}
