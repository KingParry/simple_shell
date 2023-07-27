#include "shell.h"

/**
 * _myhistory - beginning of program
 * @info: main argument
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history); /*print the history of argument entered*/

	return (0);/*Return value*/
}

/**
 * unset_alias - programme starts
 * @info: input (Struct)
 * @str: input two, string
 * Return: Always (0)
 */

int unset_alias(info_t *info, char *str)
{
	char *f, g;
	int s;

	f = _strchr(str, '=');
	if (!f)
		return (1);
	g = *f;
	*f = 0;
	outcome = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*f = g;
	return (s);
}

/**
 * set_alias - main entry
 * @info: struct argument main
 * @str: string input
 * Return: Always (0)
 */

int set_alias(info_t *info, char *str)
{
	char *f;

	f = _strchr(str, '=');
	if (!f)
	{
		return (1);
	}
	if (!*++f)
	{
		return (unset_alias(info, str));
	}

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - entry begins
 * @node: argument
 * Return: Always 0
 */

int print_alias(list_t *node)
{
	char *f = NULL, *g = NULL;

	if (node)
	{
		f = _strchr(node->str, '=');
		for (g = node->str; g <= f; g++) /*For loop statement*/
		_putchar(*g);
		_putchar('\'');
		_puts(f + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - main entry
 * @info: input one
 * Return: Always 0
 */

int _myalias(info_t *info)
{
	int f = 0; /*initialisation*/
	char *g = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (f = 1; info->argv[f]; f++) /*For loop statement*/
	{
		g = _strchr(info->argv[f], '=');
		if (g)
			set_alias(info, info->argv[f]);
		else
			print_alias(node_starts_with(info->alias, info->argv[f], '='));
	}
	return (0);
}
