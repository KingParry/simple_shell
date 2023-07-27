#include "shell.h"

/**
 **_strncpy - main entry
 *@dest: 1st input
 *@src: 2nd input
 *@n: 3rd input
 *Return: Always 0
 */
char *_strncpy(char *dest, char *src, int n)
{
	int r, s; /*Declaration*/
	char *dstn = dest;

	r = 0; /*Initialization*/
	while (src[r] != '\0' && r < n - 1)
	{
		dest[r] = src[r];
		r++;
	}
	if (r < n)
	{
		s = r;
		while (s < n)
		{
			dest[s] = '\0';
			s++;
		}
	}
	return (dstn);
}

/**
 **_strncat - main entry
 *@dest: entry one
 *@src: entry two
 *@n: entry three
 *Return: Always 0
 */

char *_strncat(char *dest, char *src, int n)
{
	int r, s;
	char *dstn = dest;

	r = 0; /*Initialisation*/
	s = 0; /*Initialisation*/
	while (dest[r] != '\0') /*While loop statement*/
		r++;
	while (src[s] != '\0' && s < n) /*While loop statement*/
	{
		dest[r] = src[s];
		r++;
		s++;
	}
	if (s < n)
		dest[r] = '\0';
	return (dstn);
}

/**
 **_strchr - program starts
 *@s: input one
 *@c: input two
 *Return: Always (0)
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)/*if condition statement*/
		{
			return (s);
		}
	} while (*s++ != '\0'); /*While loop statement*/

	return (NULL);
}
