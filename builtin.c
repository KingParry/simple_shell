#include "shell.h"

/**
 * _myexit - start of a program
 * @info: contains argument
 * Return: Always 0
 */

int _myexit(info_t *info)
{
	int exit_check;

	if (info->argv[1]) /*if condition*/
	{
		exit_check = _erratoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Not a legal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2); /*return value*/
	}
	info->err_num = -1;
	return (-2); /*return value*/
}

/**
 * _mycd - function begins
 * @info: argument one
 * Return: Always 0 (Success)
 */

int _mycd(info_t *info)
{
	char *arg, *direction, buffer[1024];
	int chgdir_retn;

	arg = getcwd(buffer, 1024);
	if (!arg) /*if condition*/
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		direction = _getenv(info, "HOME=");
		if (!direction)
			chgdir_retn =
				chdir((direction = _getenv(info, "PWD=")) ? direction : "/");
		else
			chgdir_retn = chdir(direction);
	}
	else if (_strcmp(info->argv[1], "-") == 0) /*Else if statement*/
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(arg);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chgdir_retn =
			chdir((direction = _getenv(info, "OLDPWD=")) ? direction : "/");
	}
	else
		chgdir_retn = chdir(info->argv[1]);
	if (chgdir_retn == -1)
	{
		print_error(info, "Can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - main function
 * @info: Argument 1
 * Return: Always 0
 */

int _myhelp(info_t *info)
{
	char **agumnt_array = info->argv;

	_puts("Help call Works. Function yet to be implemented... \n");
	if (0)
		_puts(*agumnt_array);

	return (0); /*Return value*/
}
