#include "shell.h"

/**
 * _memset - main function start
 * @s: entry 1
 * @b: pointer argument 2
 * @n: argument 3
 * Return: Return 0
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x ; /*intialization*/

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - Beginning of program
 * @pp: entry one
 */

void ffree(char **pp)
{
	char **l = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(l);
}

/**
 * _realloc - program start
 * @ptr: input 1
 * @old_size: input 2
 * @new_size: input 3
 * Return: Always 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *z;

	if (!ptr)
		return (malloc(new_size)); /*memory alloctn*/
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	z = malloc(new_size);
	if (!z)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		z[old_size] = ((char *)ptr)[old_size];
	free(ptr); /*freeing*/
	return (z);
}
