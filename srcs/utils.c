#include "../includes/shell.h"

int ft_strnmcpy(char **dest, char *src, int n, int m)
{
	int i = 0;

	if (n >= m || !src || !dest)
		return (-1);

	*dest = malloc(sizeof(char) * (m - n + 1));
	if (!*dest)
		return (-1);

	while ((i + n) < m && src[i + n])
	{
		(*dest)[i] = src[i + n];
		i++;
	}
	(*dest)[i] = '\0';
	return (i);
}
