#include "shell.h"

/**
 * clear_info - program begins
 * @info: struct entry
 */

void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argc = 0;
	info->argv = NULL;
	info->path = NULL;
}

/**
 * set_info - main entry
 * @info: 1st input
 * @av: 2nd input
 */

void set_info(info_t *info, char **av)
{
	int j = 0;   /*intialization*/

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (j = 0; info->argv && info->argv[j]; j++)  /*for loop*/
			;
		info->argc = j;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - programme begins
 * @info: input 1st
 * @all: input 2nd
 */

void free_info(info_t *info, int all)
{
	info->argv = NULL;
	ffree(info->argv);
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf) /*if condition*/
			free(info->arg); /*freeing*/
		if (info->env) /*if condition*/
			free_list(&(info->env));
		if (info->history) /*if condition*/
			free_list(&(info->history));
		if (info->alias) /*if condition*/
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2) /*if condition*/
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
