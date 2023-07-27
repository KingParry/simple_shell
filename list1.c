#include "shell.h"

/**
 * list_len - main function
 * @h: input
 *
 * Return: Always o
 */
size_t list_len(const list_t *h)
{
	size_t p = 0; /*intialization*/

	while (h)
	{
		h = h->next;
		p++;
	}
	return (p);
}

/**
 * list_to_strings - Begging of program
 * @head: entry 1
 * Return: Always 0
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t p = list_len(head), w;/*initialization*/
	char **strs;
	char *str;

	if (!head || !p)
		return (NULL);
	strs = malloc(sizeof(char *) * (p + 1));
	if (!strs)
		return (NULL);
	for (p = 0; node; node = node->next, p++) /*for loop*/
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (w = 0; w < p; w++)
				free(strs[w]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[p] = str;
	}
	strs[p] = NULL;
	return (strs);
}


/**
 * print_list - program starts
 * @h: first entry
 * Return:size
 */

size_t print_list(const list_t *h)
{
	size_t l = 0;

	while (h)
	{
		_puts(convert_number(h->numb, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		l++;
	}
	return (l);
}

/**
 * node_starts_with - main program
 * @node: input one
 * @prefix: input two
 * @c: input three
 * Return: match all nodes
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *m = NULL; /*Initialization*/

	while (node)
	{
		m = starts_with(node->str, prefix);
		if (m && ((c == -1) || (*m == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - main program
 * @head: input 1
 * @node: input 1
 * Return: Always 0
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t e = 0;

	while (head)
	{
		if (head == node)
			return (e);
		head = head->next;
		e++;
	}
	return (-1);
}
