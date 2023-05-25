#include "main.h"

/**
 * _get_sig_int_ - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void _get_sig_int_(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
