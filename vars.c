#include "shell.h"

/**
 * is_chain - Begginning of function
 * @info: input number one
 * @buf: input number two
 * @p: input number three
 * Return: Always 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t k = *p; /*intialization of the f variable*/

	if (buf[k] == '|' && buf[k + 1] == '|')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[k] == '&' && buf[k + 1] == '&')
	{
		buf[k] = 0;
		k++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[k] == ';') /* else condition */
	{
		buf[k] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = k;
	return (1);
}

/**
 * check_chain - entry main
 * @info: input first
 * @buf: second input
 *
 * @p: input three
 * @i: input four
 * @len: input five
 * Return: Always 0
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t mok = *p; /*intialization of mok*/

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			mok = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			mok = len;
		}
	}

	*p = mok;
}

/**
 * replace_alias - main function begins
 * @info: input1
 * Return: Always 0
 */

int replace_alias(info_t *info)
{
	int b;  /*declaration of b*/
	list_t *node;   /*declaration of node*/
	char *a;   /*declaration of ponter a*/

	for (b = 0; b < 10; b++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		a = _strchr(node->str, '=');
		if (!a)
			return (0);
		a = _strdup(a + 1);
		if (!a)
			return (0);
		info->argv[0] = a;
	}
	return (1);
}

/**
 * replace_vars - Beginning of program
 * @info: input information
 * Return: Always 0
 */

int replace_vars(info_t *info)
{
	int n = 0;    /*initialisation of n*/
	list_t *node;     /*declaration of pointer node*/

	for (n = 0; info->argv[n]; n++)
	{
		if (info->argv[n][0] != '$' || !info->argv[n][1])
			continue;

		if (!_strcmp(info->argv[n], "$?"))
		{
			replace_string(&(info->argv[n]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[n], "$$"))
		{
			replace_string(&(info->argv[n]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[n][1], '=');
		if (node)
		{
			replace_string(&(info->argv[n]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[n], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - beginning of program
 * @old: previous string
 * @new: new string
 * Return: Always 0
 */

int replace_string(char **old, char *new)
{
	free(*old);   /*freeing of memory*/
	*old = new;  /* pointer old being assigned to new*/
	return (1);
}
