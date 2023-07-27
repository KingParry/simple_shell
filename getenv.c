#include "shell.h"

/**
 * get_environ - main entry
 * @info: struct arguments
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - entry begins
 * @info: input one
 * Return: Always 0
 * @var: input two
 */

int _unsetenv(info_t *info, char *var)
{
	size_t f = 0;
	char *g;
	list_t *node = info->env;

	if (!node || !var)
	{
		return (0);
	}
	while (node)
	{
		g = starts_with(node->str, var);
		if (g && *g == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), f);
			f = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		f++;
	}
	return (info->env_changed);
}

/**
 * _setenv - main function
 * @info: 1st entry
 * @var: 2nd entry
 * @value: 3rd entry
 * Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	list_t *node;
	char *k;
	char *buffy = NULL;

	if (!var || !value)
	{
		return (0);
	}
	buffy = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffy)
	{
		return (1);
	}
	_strcpy(buffy, var);
	_strcat(buffy, "=");
	_strcat(buffy, value);
	node = info->env;
	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			free(node->str);
			node->str = buffy;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffy, 0);
	free(buffy);
	info->env_changed = 1;
	return (0);
}
