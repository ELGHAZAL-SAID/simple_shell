#include "main.h"

/**
 * _strcat - concatenating two strings
 * @dest: char pointer
 * @src: const char
 * Return: the dest variable
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
		i++;

	for (j = 0; src[j] != '\0'; j++)
		dest[i] = src[j], i++;

	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string to by src variable.
 * @dest: Type char pointer
 * @src: Type char pointer
 * Return: the dest pointer.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - compares two strings.
 * @s1: string compared
 * @s2: string compared
 * Return: 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - locating a char in a str,
 * @s: string.
 * @c: char.
 * Return: the pointer to the first the character.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strspn - length getting of a prefix.
 * @s:segment.
 * @accept: bytes.
 * Return: number of bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
