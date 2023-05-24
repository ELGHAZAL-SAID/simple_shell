#include "main.h"

/**
 * rd_ln - read the command.
 * @string: the string.
 * Return: num of chars.
 */
size_t rd_ln(char **string)
{
	ssize_t x = 0, size = 0, error = 0, error1 = 0, y = 0;
	char buffer[1024];

	while (error1 == 0 && (x = read(STDIN_FILENO, buffer, 1024 - 1)))
	{
		if (x == -1)
			return (-1);

		buffer[x] = '\0';

		for (y = 0; buffer[y] != '\0'; y++)
		{
			if (buffer[y] == '\n')
				error1 = 1;
		}

		if (error == 0)
		{
			x++;
			*string = malloc(sizeof(char) * x);
			*string = _strcpy(*string, buffer);
			size = x;
			error = 1;
		}
		else
		{
			size += x;
			*string = _strcat(*string, buffer);
		}
	}
	return (size);
}
