#include "shell.h"

/**
 * _eputs - function entry
 * @str: input one
 * Return: (void)
 */

void _eputs(char *str)
{
	int k = 0;

	if (!str)
	{
		return;
	}
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - start of program
 * @c: char input
 * Return: Always one
 */

int _eputchar(char c)
{
	static int k; /*Declaratiion*/
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || k >= WRITE_BUF_SIZE) /*if statement*/
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - main entry
 * @c: first argument
 * @fd: second argument
 * Return: Always 0
 */

int _putfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putsfd - programme entry
 * @str: argmnt one
 * @fd: argmnt two
 * Return: Always 0
 */

int _putsfd(char *str, int fd)
{
	int k = 0; /*Initialization*/

	if (!str) /*If condition*/
	{
		return (0);
	}
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}
