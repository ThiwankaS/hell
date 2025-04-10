#include "../includes/shell.h"

int ft_isspace(int c);
int get_num_args(char *str);
static char *get_command2(char *token);

t_cmd *handel_output(char *token)
{
	/**
	 * example of the command format
	 * echo "the string need to write in to the file" > file.txt
	*/
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		return (NULL);
	cmd->type = OPRD_CMD;
	cmd->command = get_command2(token);
	char **args = malloc(sizeof(char *) * 2);
	args[0] = get_command2(token);
	args[1] = NULL;
	cmd->args = args;
	cmd->num_args = 2;
	cmd->next = NULL;
	return (cmd);
}

static char *get_command2(char *token)
{
	int i = 1, start = 0;
	char *str = ft_strchr(token, '>'), c, *res;
	while(str && str[i] && ft_isspace(str[i]))
		i++;
	start = i;
	if(str[i] == '\'' || str[i] == '"')
	{
		c = str[i];
		i++;
		while(str && str[i] && str[i] != c)
			i++;
		i++;
	}
	else
	{
		while(str && str[i] && !ft_isspace(str[i]))
			i++;
	}
	res = ft_strnmdup(str, start, i);
	return (res);
}



