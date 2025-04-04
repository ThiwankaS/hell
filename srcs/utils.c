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
		printf("envp : {%s}\n", current->envp[0]);
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
