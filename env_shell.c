#include "main.h"

/**
* env_shell - prints the current environnment of the shell
* @token : command line
* Return: non
*/


void env_shell(char **token __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
