#include "shell.h"

/**
 * hsh - main program shell
 * @info: entry one
 * @av: entry two
 * Return: Always 0
 */

int hsh(info_t *info, char **av)
{
	ssize_t cn = 0; /*Initialisation*/
	int gig = 0; /*Initialisation*/

	while (cn != -1 && gig != -2) /*while looping*/
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		cn = get_input(info);
		if (cn != -1) /*if condition statement*/
		{
			set_info(info, av);
			gig = find_builtin(info);
			if (gig == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (gig == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (gig);
}

/**
 * find_builtin - beginning of program
 * @info: argument
 * Return: Always (0)
 */

int find_builtin(info_t *info)
{
	int m, bb = -1; /*declaration and initialisation*/
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (m = 0; builtintbl[m].type; m++) /*for looping*/
		if (_strcmp(info->argv[0], builtintbl[m].type) == 0)
		{
			info->line_count++;
			bb = builtintbl[m].func(info);
			break;
		}
	return (bb);
}

/**
 * find_cmd - function starts
 * @info: entry 1
 * Return:  void
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int u, p; /*Declaration*/

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (u = 0, p = 0; info->arg[u]; u++) /*for looping*/
		if (!is_delim(info->arg[u], " \t\n"))
			p++;
	if (!p) /*if conditional statement*/
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=") /*if statement*/
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "Not Found\n");
		}
	}
}

/**
 * fork_cmd - main programme
 * @info: argument
 * Return: void
 */

void fork_cmd(info_t *info)
{
	pid_t chy;/*Declaration*/

	chy = fork();
	if (chy == -1) /*if condition statement*/
	{
		perror("Error:");
		return;
	}
	if (chy == 0) /*if condition statement*/
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status)) /*if condition statement*/
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126) /*if condition statement*/
				print_error(info, "Permission Denied\n"); /*Error printing*/
		}
	}
}
