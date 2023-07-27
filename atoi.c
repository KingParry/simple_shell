#include "shell.h"

/**
 * interactive - main entry
 * @info: address info
 * Return: Always 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - main entry
 * @a: argument 1
 * @delim: argument 2
 * Return: Always 0
 */

int is_delim(char a, char *delim)
{
	while (*delim)   /*while looping*/
		if (*delim++ == a)
		{
			return (1);   /*Return*/
		}
	return (0);
}

/**
 * _isalpha - main function
 * @a: argument 1
 * Return: Always 0
 */
int _isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) /*if condition*/
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - a function
 * @s: string
 * Return: Always 0
 */
int _atoi(char *s)
{
	int atom, tsynn = 1, sight = 0, g; /*declaration and initialization*/
	unsigned int outcum = 0;

	for (atom = 0; s[atom] != '\0' && sight != 2; atom++)
	{
		if (s[atom] == '-') /*if condition*/
			tsynn *= -1;

		if (s[atom] >= '0' && s[atom] <= '9') /*if condition*/
		{
			sight = 1;
			outcum *= 10;
			outcum += (s[atom] - '0');
		}
		else if (sight == 1)
			sight = 2;
	}

	if (tsynn == -1)
	{
		g = -outcum;
	}
	else
	{
		g = outcum;
	}
	return (g);
}
