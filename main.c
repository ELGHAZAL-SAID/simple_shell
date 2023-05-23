#include "main.h"

/**
 * main - shell programe.
 *
 * return: 0.
 */

int main()
{
	char *buffer = 0;
	size_t size = 0;
	pid_t pid;

	while (1)
	{
		display();
		getline(buffer, size, stdin);
		pid = fork();
	}
}
