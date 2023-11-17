#include "shell.h"

/**
 * aff - imprime an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void aff(char *str)
{
	int in = 0;

	if (!str)
		return;
	while (str[in] != '\0')
	{
		ecrire(str[in]);
		in++;
	}
}

/**
 * ecrire - writes the character c to stderr
 * @ct: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int ecrire(char ct)
{
	static int in;
	static char buf[WRITE_BUF_SIZE];

	if (ct == BUF_FLUSH || in >= WRITE_BUF_SIZE)
	{
		write(2, buf, in);
		in = 0;
	}
	if (ct != BUF_FLUSH)
		buf[in++] = ct;
	return (1);
}

/**
 * ecritfd - writes the character c to given fd
 * @ct: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int ecritfd(char ct, int fd)
{
	static int in;
	static char buf[WRITE_BUF_SIZE];

	if (ct == BUF_FLUSH || in >= WRITE_BUF_SIZE)
	{
		write(fd, buf, in);
		in = 0;
	}
	if (ct != BUF_FLUSH)
		buf[in++] = ct;
	return (1);
}

/**
 * _afffd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _afffd(char *str, int fd)
{
	int in = 0;

	if (!str)
		return (0);
	while (*str)
	{
		in += _afffd(*str++, fd);
	}
	return (in);
}

