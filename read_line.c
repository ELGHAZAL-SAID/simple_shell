#include "main.h"

/**
 * read_line - reads command into buffer
 * @str: the command.
 * Return: number of characters.
 */
size_t read_line(char **str)
{
    ssize_t x = 0, sz = 0;
    char *buf = NULL;
    size_t bufsize = 0;

    x = getline(&buf, &bufsize, stdin);
    while (x != -1)
    {
        if (x > 0 && buf[x - 1] == '\n')
        {
            buf[x - 1] = '\0';
            sz = x - 1;
            break;
        }

        if (*str == NULL)
        {
            *str = strdup(buf);
            sz = x;
        }
        else
        {
            *str = realloc(*str, sz + x);
            strcat(*str, buf);
            sz += x;
        }
    }

    free(buf);
    return (sz);
}
