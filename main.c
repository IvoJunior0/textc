#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// argv[1]: filename.
// argv[2]: option.
int main(int argc, char *argv[])
{
	FILE *fptr;
	char data[1000];

	if (argc < 3)
	{
		printf("Quantidade de argumentos inválida.\n");
		return 0;
	}

	if (argv[2][0] == 'r')
	{
		fptr = fopen(argv[1], "r");

		if (fptr == NULL)
		{
			perror("Arquivo não foi aberto.\n");
			return 0;
		}
		
		char result[10000];
		while(fgets(result, sizeof result, fptr) != NULL)
		{
			printf("%s", result);
		}
		fclose(fptr);
	}
	else if (argv[2][0] == 'w')
	{
		fptr = fopen(argv[1], "w");

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
		printf("Opção inválida.\n");
		return 1;
	}
	return 0;
}
