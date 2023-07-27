#include "shell.h"

/**
 * _myenv - prints current environmnt
 * @info: inputs
 * Return: Always (0)
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

/**
 * _getenv - beginning entry
 * @info: argument one
 * @name: argument two
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *u;

	while (node)
	{
		u = starts_with(node->str, name);
		if (u && *u)
		{
			return (u);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - main function
 * @info: input one
 * Return: 0 (Success)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect numba of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * _myunsetenv - programme starts
 * @info: inputs
 * Return: Success(0)
 */

int _myunsetenv(info_t *info)
{
	int q;

	if (info->argc == 1)
	{
		_eputs("Not enough arguments.\n");
		return (1);
	}
	for (q = 1; q <= info->argc; q++)
		_unsetenv(info, info->argv[q]);
	return (0);
}

/**
 * populate_env_list - function begins
 * @info: input one
 * Return: 0 (Success)
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t u;

	for (u = 0; environ[u]; u++)
		add_node_end(&node, environ[u], 0);
	info->env = node;
	return (0);
}
