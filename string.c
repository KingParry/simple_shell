#include "shell.h"

/**
 * _strlen - beginning of function
 * @s: argument
 * Return: Always 0
 */

int _strlen(char *s)
{
	int n = 0;  /*Initialization*/

	if (!s)
		return (0);

	while (*s++) /*while looping*/
		n++;
	return (n);
}

/**
 * _strcmp - main entry
 * @s1: argument one
 * @s2: argument two
 * Return: Always 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2) /*checks s2 with s2\1*/
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++; /*Increamental on s1*/
		s2++; /*Increamental on S2*/
	}
	if (*s1 == *s2)
		return (0); /*return value*/
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function begins
 * @haystack: 1st arguement
 * @needle: 2nd argument
 * Return: Always 0
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++) /*conditional if Statement*/
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - program start
 * @dest: input one
 * @src: input two
 * Return: Always 0
 */

char *_strcat(char *dest, char *src)
{
	char *g = dest;   /*Initialization*/

	while (*dest) /*While loop*/
		dest++;
	while (*src) /*While loop*/
		*dest++ = *src++;
	*dest = *src;
	return (g);
}
