#include "main.h"

/**
 * ln_br - assigning the line variable for ln_br
 * @lineptr: Buffer storing the input string
 * @buffer: string that is called to line
 * @n: line size
 * @j: buffer size
 */
void ln_br(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFFERSIZE)
			*n = j;

		else
			*n = BUFFERSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFFERSIZE)
			*n = j;
		else
			*n = BUFFERSIZE;
		*lineptr = buffer;
	}
	else
		_strcpy(*lineptr, buffer), free(buffer);

}
/**
 * ln_getter - Read input
 * @lineptr: buffer storing the input
 * @n: lineptr size
 * @stream: stream to be read
 * Return: number bytes
 */
ssize_t ln_getter(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFFERSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFFERSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	ln_br(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
