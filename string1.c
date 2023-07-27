#include "shell.h"

/**
 * _strcpy - start functn
 * @dest: argument one
 * @src: argument two source
 * Return: Always (0)
 */

char *_strcpy(char *dest, char *src)
{
	int h = 0; /*initialisation*/

	if (dest == src || src == 0) /*if condition*/
		return (dest);
	while (src[h]) /*while looping*/
	{
		dest[h] = src[h];
		h++;
	}
	dest[h] = 0;
	return (dest);
}

/**
 * _strdup - main program
 * @str: argument string
 * Return: Always 0
 */

char *_strdup(const char *str)
{
	int d = 0;
	char *e;

	if (str == NULL)
		return (NULL);
	while (*str++)
		d++;
	e = malloc(sizeof(char) * (d + 1));
	if (!e)
		return (NULL);
	for (d++; d--;)
		e[d] = *--str;
	return (e);
}

/**
 * _puts - program start
 * @str: argument string
 * Return: Always (0)
 */

void _puts(char *str)
{
	int x = 0; /*Intialization*/

	if (!str)
		return;
	while (str[x] != '\0') /*while looping*/
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - main function
 * @c: input main
 * Return: Always 0
 */

int _putchar(char c)
{
	static int f; /*Declaration of f*/
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || f >= WRITE_BUF_SIZE) /*if conditional statement*/
	{
		write(1, buf, f);
		f = 0;
	}
	if (c != BUF_FLUSH)
		buf[f++] = c;
	return (1);
}
