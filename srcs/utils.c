#include "../includes/shell.h"

char *ft_strnmdup(char const *src, int n , int m)
{
	int i = 0;
	char *dest;

	if(!src || m == 0)
		return (NULL);
	dest = malloc(sizeof(char) * ((m - n) + 1));
	if(!dest)
		return (NULL);
	while(src && src[i + n] && (i + n) < m)
	{
		dest[i] = src[i + n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

int ft_isspace(int c)
{
	if(c == ' ' || c == '\f' || c == '\t' || c == '\v' || c == '\r' || c == '\n')
		return (1);
	return (0);
}

int get_num_args(char *str)
{
	int i = 0, count = 1, flag = 0, space = 0;
	if(!str)
		return (0);
	while(str[i])
	{
		if(str[i] == '"' || str[i] == '\'')
		{
			if(!flag)
				flag = 1;
			else
				flag = 0;
		}
		if(ft_isspace(str[i]) && !flag && !space)
		{
			count++;
			space = 1;
		}
		if(!ft_isspace(str[i]))
			space = 0;
		i++;
	}
	return (count);
}

void print_args(char **args, int size)
{
	int i = 0;
	while(i <= size)
	{
		printf("args[%d] : %s\n", i, args[i]);
		i++;
	}
}

void print_cmd(t_cmd *cmd)
{
	t_cmd *current = cmd;
	while(current)
	{
		printf("command : %s\n", current->command);
		printf("args : \n");
		print_args(current->args, current->num_args);
		current = current->next;
	}
}

void print(t_list *list, char *msg)
{
	printf("\n%s\n", msg);
	t_list *current = list;
	while(current)
	{
		printf("%s\n", current->token);
		current = current->next;
	}
	printf("------------------------------------\n");
}
