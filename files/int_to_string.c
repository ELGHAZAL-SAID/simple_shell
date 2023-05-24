#include "main.h"

/**
 * number_len - counts number.
 * @n: number
 * Return: number of digits.
 */
int number_len(int n)
{
	int cnt = 0, x = n;

	while (x > 9 || x < -9)
	{
		x /= 10;
		cnt++;
	}
	return (cnt);
}
/**
 * digit_to_str - int to string.
 * @number: int
 * Return: the string.
 */

char *digit_to_str(int number)
{
	int q, r, s = 0, t = 0, x;
	char *res;

	q = number;
	r = 1;

	if (number < 0)
		t = 1;
	res = malloc(sizeof(char) * (number_len(q) + 2 + t));
	if (res == NULL)
		return (NULL);
	if (number < 0)
	{
		res[s] = '-';
		s++;
	}
	for (x = 0; q > 9 || q < -9; x++)
	{
		q /= 10;
		r *= 10;
	}
	for (q = number; x >= 0; x--)
	{
		if (q < 0)
		{
			res[s] = (q / r) * -1 + '0';
			s++;
		}
		else
		{
			res[s] = (q / r) + '0';
			s++;
		}
		q %= r;
		r /= 10;
	}
	res[s] = '\0';
	return (res);

}
