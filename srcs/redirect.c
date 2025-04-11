#include "../includes/shell.h"

int ft_isspace(int c);
static char *set_filename(char *token);
static char *get_command_oprd(char *token);
static char *set_path_name(char *token);
static char **set_arg_array_oprd(int num_args, char *token);

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
	cmd->command = set_path_name(token);
	cmd->filename = set_filename(token);
	cmd->num_args = get_num_args(token);
	cmd->args = set_arg_array_oprd(cmd->num_args, token);
	cmd->next = NULL;
	return (cmd);
}

static char **set_arg_array_oprd(int num_args, char *token)
{
	char **args = malloc(sizeof(char *) * (num_args + 1));
	args[0] = set_path_name(token);
	args[1] = ft_strdup("file.txt");
	args[2] = NULL;
	return(args);
}

static char *set_filename(char *token)
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

static char *get_command_oprd(char *token)
{
	int i = 0, start = 0;
	char c, *res;
	while(token && token[i] && ft_isspace(token[i]))
		i++;
	if(token[i] == '\'' || token[i] == '"')
	{
		c = token[i];
		i++;
		start = i;
		while(token && token[i] && token[i] != c)
			i++;
	}
	else
	{
		start = i;
		while(token && token[i] && !ft_isspace(token[i]))
			i++;
	}
	res = ft_strnmdup(token, start, i);
	return (res);
}

static char *set_path_name(char *token)
{
	char *path = ft_strdup("/bin/");
	char *command = ft_strjoin(path, get_command_oprd(token));
	free(path);
	return (command);
}



