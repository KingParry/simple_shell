#include "shell.h"

/**
 * bfree - start of function
 * @ptr: argument one
 * Return: Always 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr) /*if statement*/
	{
		free(*ptr); /*freeing mem*/
		*ptr = NULL; /*pointer to null*/
		return (1); /*return*/
	}
	return (0);
}
