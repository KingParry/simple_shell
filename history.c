#include "shell.h"

/**
 * get_history_file - start of program
 * @info: argument
 * Return: Always (0)
 */
char *get_history_file(info_t *info)
{
	char *buffy, *direct; /*intialisatioin*/

	direct = _getenv(info, "HOME=");
	if (!direct) /*if condition*/
		return (NULL);
	buffy = malloc(sizeof(char) * (_strlen(direct) + _strlen(HIST_FILE) + 2));
	if (!buffy)
		return (NULL);
	buffy[0] = 0;
	_strcpy(buffy, direct); /*copy string*/
	_strcat(buffy, "/");
	_strcat(buffy, HIST_FILE);
	return (buffy);
}

/**
 * write_history - Origin of function
 * @info: data entry
 * Return: Always (0)
 */

int write_history(info_t *info)
{
	ssize_t fudu;
	char *fnym = get_history_file(info); /* writing history*/
	list_t *s = NULL;

	if (!fnym)
		return (-1);

	fudu = open(fnym, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fnym);
	if (fudu == -1)
		return (-1);
	for (s = info->history; s; s = s->next)
	{
		_putsfd(s->str, fudu);
		_putfd('\n', fudu);
	}
	_putfd(BUF_FLUSH, fudu);
	close(fudu);
	return (1);
}

/**
 * read_history - function general
 * @info: input entry
 * Return: Always (0)
 */

int read_history(info_t *info)
{
	int v = 0, endd = 0, countax = 0;
	ssize_t fudu, redlenf, filxize = 0;
	struct stat st;
	char *buffy = NULL, *filenym = get_history_file(info);

	if (!filenym)
		return (0);

	fudu = open(filenym, O_RDONLY);
	free(filenym);
	if (fudu == -1)
		return (0);
	if (!fstat(fudu, &st))
		filxize = st.st_size;
	if (filxize < 2)
		return (0);
	buffy = malloc(sizeof(char) * (filxize + 1));
	if (!buffy)
		return (0);
	redlenf = read(fudu, buffy, filxize);
	buf[filxize] = 0;
	if (redlenf <= 0)
		return (free(buffy), 0);
	close(fudu);
	for (v = 0; v < filxize; v++)
		if (buffy[v] == '\n')
		{
			buffy[v] = 0;
			build_history_list(info, buffy + endd, countax++);
			endd = v + 1;
		}
	if (endd != v)
		build_history_list(info, buffy + endd, countax++);
	free(buffy);
	info->histcount = countax;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - start entry
 * @info: input 1st
 * @buf: input 2nd
 * @linecount: input 3rd
 * Return: Always 0
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *p = NULL; /*initialization*/

	linecount = 0;
	if (info->history)
		p = info->history;
	add_node_end(&p, buf, linecount);

	if (!info->history)
		info->history = p;
	return (0);
}

/**
 * renumber_history - main entry
 * @info: argument
 * Return: Always (0)
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int l = 0; /*initialization*/

	while (node)
	{
		node->numb = l++; /*incremental*/
		node = node->next;
	}
	return (info->histcount = v);
}
