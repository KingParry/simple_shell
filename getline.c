#include "shell.h"

/**
 * input_buf - main function
 * @info: struct entry one
 * @buf: entry two
 * @len: entry three
 * Return: Always 0
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t f = 0; /*initialisation*/
	size_t den_p = 0; /*initialisation*/

	if (!*len) /*if stathement*/
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		f = getline(buf, &den_p, stdin);
#else
		f = _getline(info, buf, &den_p);
#endif
		if (f > 0)
		{
			if ((*buf)[f - 1] == '\n')
			{
				(*buf)[f - 1] = '\0';
				f--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = f;
				info->cmd_buf = buf;
			}
		}
	}
	return (f);
}

/**
 * get_input - function starts
 * @info: struct argument
 * Return: Always 0
 */
ssize_t get_input(info_t *info)
{
	static char *buffy;
	static size_t k, l, ken;
	ssize_t p = 0;
	char **buf_m = &(info->arg), *g;

	_putchar(BUF_FLUSH);
	p = input_buf(info, &buffy, &ken);
	if (p == -1)
		return (-1);
	if (ken)
	{
		l = k;
		g = buffy + k;

		check_chain(info, buffy, &l, k, ken);
		while (l < ken)
		{
			if (is_chain(info, buffy, &l))
				break;
			l++;
		}

		k = l + 1;
		if (k >= ken)
		{
			k = ken = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_m = g;
		return (_strlen(g));
	}

	*buf_m = buffy;
	return (p);
}

/**
 * read_buf - main function
 * @info: struct arg 1
 * @buf: arg 2
 * @i: arg 3
 * Return: Always 0
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t j = 0; /*initialization*/

	if (*i) /*if statement*/
		return (0);
	j = read(info->readfd, buf, READ_BUF_SIZE);
	if (j >= 0)
		*i = j;
	return (j); /*Return value*/
}

/**
 * _getline - program starts
 * @info: first argument
 * @ptr: second argument
 * @length: there argument
 * Return: Always 0
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static size_t aank, ben;
	static char buf[READ_BUF_SIZE];
	size_t bat;
	ssize_t zoc = 0, nert = 0;
	char *x = NULL, *new_r = NULL, *s;

	x = *ptr;
	if (x && length)
		zoc = *length;
	if (aank == ben)
		aank = ben = 0;

	nert = read_buf(info, buf, &ben);
	if (nert == -1 || (nert == 0 && ben == 0))
		return (-1);

	s = _strchr(buf + aank, '\n');
	bat = s ? 1 + (unsigned int)(s - buf) : ben;
	new_r = _realloc(x, zoc, zoc ? zoc + bat : bat + 1);
	if (!new_r)
		return (x ? free(x), -1 : -1);

	if (zoc)
		_strncat(new_r, buf + aank, bat - aank);
	else
		_strncpy(new_r, buf + aank, bat - aank + 1);

	zoc += bat - aank;
	aank = bat;
	x = new_r;

	if (length)
		*length = zoc;
	*ptr = x;
	return (zoc);
}

/**
 * sigintHandler - function starts
 * @sig_num: only entry
 * Return: Always 0
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
