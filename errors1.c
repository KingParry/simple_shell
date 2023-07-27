#include "shell.h"

/**
 * _erratoi - beginning of program
 * @s: argument
 * Return: Always 0
 */
int _erratoi(char *s)
{
	int k = 0; /*Initialization*/
	unsigned long int p = 0;

	if (*s == '+') /*if statement*/
		s++;
	for (k = 0;  s[k] != '\0'; k++) /*for loop statement*/
	{
		if (s[k] >= '0' && s[k] <= '9') /*if condition statement*/
		{
			p *= 10;
			p += (s[k] - '0');
			if (p > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);/*return value*/
		}
	}
	return (p);
}

/**
 * print_error - function main entry
 * @info: struct argument one
 * @estr: argument two strng
 * Return: Always 0
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname); /*print error statements*/
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO); /*print error statements*/
	_eputs(": ");
	_eputs(info->argv[0]); /*print error statements*/
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function begins
 * @input: entry one
 * @fd: entry two
 * Return: print number of chars
 */

int print_d(int input, int fd)
{
	int m, nomba = 0; /*Delcaration and initialization*/
	int (*__putchar)(char) = _putchar;
	unsigned int _kkl_, prsnt; /*Declaration*/

	if (fd == STDERR_FILENO) /*if condition*/
		__putchar = _eputchar;
	if (input < 0) /*if condition*/
	{
		_kkl_ = -input;
		__putchar('-');
		nomba++;
	}
	else
		_kkl_ = input;
	prsnt = _kkl_;
	for (m = 1000000000; m > 1; m /= 10) /*for loop statement*/
	{
		if (_kkl_ / m)
		{
			__putchar('0' + prsnt / m);
			nomba++;
		}
		prsnt %= m;
	}
	__putchar('0' + prsnt);
	nomba++;

	return (nomba);
}

/**
 * convert_number - start the program
 * @num: argument 1
 * @base: argument 2
 * @flags: arguement 3
 * Return: string returned value
 */
char *convert_number(long int num, int base, int flags)
{
	static char *unioon;
	char symstm = 0;
	static char buffer[50];
	char *pnp;
	unsigned long aat = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		aat = -num;
		symstm = '-';

	}
	unioon = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pnp = &buffer[49];
	*pnp = '\0';

	do	{
		*--pnp = unioon[aat % base];
		aat /= base;
	} while (aat != 0);

	if (symstm)
		*--pnp = symstm;
	return (pnp);
}

/**
 * remove_comments - main entry
 * @buf: input one
 * Return: Always 0
 */
void remove_comments(char *buf)
{
	int aat;

	for (aat = 0; buf[aat] != '\0'; aat++) /*For loop statement*/
		if (buf[aat] == '#' && (!aat || buf[aat - 1] == ' '))
		{
			buf[aat] = '\0';
			break;
		}
}
