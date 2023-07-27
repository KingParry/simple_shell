#include "shell.h"

/**
 * **strtow - main programme
 * @str: argument 1
 * @d: argument 2
 * Return: Always (0)
 */

char **strtow(char *str, char *d)
{
	int k, l, m, q; /*de-claration*/
	int ww = 0; /*In-itialization*/
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (k = 0; str[k] != '\0'; k++) /*for looping*/
		if (!is_delim(str[k], d) && (is_delim(str[k + 1], d) || !str[k + 1]))
			ww++; /*increament*/

	if (ww == 0)
		return (NULL);
	s = malloc((1 + ww) * sizeof(char *));
	if (!s)
		return (NULL);
	for (k = 0, l = 0; l < ww; l++)  /*for looping*/
	{
		while (is_delim(str[k], d))
			k++;
		m = 0;
		while (!is_delim(str[k + m], d) && str[k + m])
			m++;
		s[l] = malloc((m + 1) * sizeof(char));
		if (!s[l])
		{
			for (m = 0; m < l; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < m; q++)   /*for looping*/
			s[l][q] = str[k++];
		s[l][q] = 0;
	}
	s[l] = NULL;
	return (s);
}

/**
 * **strtow2 - program entry
 * @str: argument 1
 * @d: argument 2
 * Return: Always (0)
 */
char **strtow2(char *str, char d)
{
	int a, b, f, y; /*Declaration*/
	int wsw = 0; /*initialization*/
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			wsw++;
	if (wsw == 0)
		return (NULL);
	s = malloc((1 + wsw) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < wsw; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		f = 0;
		while (str[a + f] != d && str[a + f] && str[a + f] != d)
			f++;
		s[b] = malloc((f + 1) * sizeof(char));
		if (!s[b])
		{
			for (f = 0; f < b; f++)
				free(s[f]);
			free(s);
			return (NULL);
		}
		for (y = 0; y < f; y++)
			s[b][y] = str[a++];
		s[b][y] = 0;
	}
	s[b] = NULL;
	return (s);
}
