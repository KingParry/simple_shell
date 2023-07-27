#include "shell.h"

/**
 * is_cmd - main function
 * @info: struct stat st
 * @path: path to file
 * Return: Always 0
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))  /*if condition*/
		return (0);

	if (st.st_mode & S_IFREG)  /*if condition*/
	{
		return (1); /*Return*/
	}
	return (0);
}

/**
 * dup_chars - Start of program
 * @pathstr: input 1
 * @start: input 2
 * @stop: input 3
 * Return: Always 0`
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int b = 0, t = 0; /*initialisation*/

	for (t = 0, b = start; b < stop; b++) /*for loop statement*/
		if (pathstr[b] != ':') /*if condition statement*/
			buf[t++] = pathstr[b];
	buf[t] = 0;
	return (buf); /*return value*/
}

/**
 * find_path - main program
 * @info: entry first
 * @pathstr: entry second
 * @cmd: entry third
 * Return: Always (0)
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, u = 0; /*initialization*/
	char *k;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			k = dup_chars(pathstr, u, a);
			if (!*k)
				_strcat(k, cmd);
			else
			{
				_strcat(k, "/");
				_strcat(k, cmd);
			}
			if (is_cmd(info, k))
				return (k);
			if (!pathstr[a])
				break;
			u = a;
		}
		a++; /*incremental*/
	}
	return (NULL);
}
