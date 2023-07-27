#include "shell.h"

/**
 * main - program starts
 * @ac: entry one
 * @av: entry two
 * Return: Always 0
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT }; /*In-itialisation*/
	int w = 0; /*In-tialization*/

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (w)
			: "r" (w));

	if (ac == 2)
	{
		w = open(av[1], O_RDONLY); /*file doc opens*/
		if (w == -1)
		{
			if (errno == EACCES) /*if statement*/
				exit(126);
			if (errno == ENOENT) /*if statement*/
			{
				_eputs(av[0]);
				_eputs(": 0: Can't Open.. ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = w;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
