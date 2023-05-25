#include "main.h"

/**
 * _get_sig_int_ - Handle crtl + c
 * @sig: handling Signal
 */
void _get_sig_int_(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
