#include "shell.h"

/**
 * add_node - programme beggins
 * @head: first entry
 * @str: second entry
 * @numb: third entry
 * Return: Always (0)
 */
list_t *add_node(list_t **head, const char *str, int numb)
{
	list_t *y; /*declaring the variable*/

	if (!head)
		return (NULL);
	y = malloc(sizeof(list_t)); /*memory allocation*/
	if (!y)
		return (NULL); /*Returns Null*/
	_memset((void *)y, 0, sizeof(list_t));
	y->numb = numb;
	if (str)
	{
		y->str = _strdup(str);
		if (!y->str)
		{
			free(y); /* freeing memory allocation*/
			return (NULL);
		}
	}
	y->next = *head;
	*head = y;
	return (y);
}

/**
 * add_node_end - main functn begginss
 * @head: 1st input
 * @str: 2nd input
 * @numb: 3rd input
 * Return: Always (0)
 */
list_t *add_node_end(list_t **head, const char *str, int numb)
{
	list_t *neat, *node; /*declaration*/

	numb = 0;
	if (!head)
		return (NULL);

	node = *head;
	neat = malloc(sizeof(list_t));
	if (!neat)
		return (NULL);
	_memset((void *)neat, 0, sizeof(list_t));
	neat->numb = numb;
	if (str)
	{
		neat->str = _strdup(str);
		if (!neat->str)
		{
			free(neat);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = neat;
	}
	else
		*head = neat;
	return (neat);
}

/**
 * print_list_str - start of programme
 * @h: entry number 1
 * Return: Always 0
 */

size_t print_list_str(const list_t *h)
{
	size_t x = 0; /*intialization*/

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++; /*incremental*/
	}
	return (x);
}

/**
 * delete_node_at_index - main function startss
 * @head: entry 1
 * @index: 2nd input
 * Return: Always 0
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *vvv; /*declaration of variables*/
	unsigned int z = 0; /*initialization of z variable*/

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (z == index)
		{
			vvv->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		z++;
		vvv = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - Begins
 * @head_ptr: first input
 * Return: Always 0
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *pan, *head; /*declaration of variables*/

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		pan = node->next;
		free(node->str);
		free(node); /*freeing memory*/
		node = pan;
	}
	*head_ptr = NULL;
}
