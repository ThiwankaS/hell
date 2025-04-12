#include "../includes/shell.h"

static char **set_arg_array_quoted(char *token);
static char *set_command(char *token);

t_cmd *handle_quoted(char *token)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		return (NULL);
	cmd->type = SMPL_CMD;
	cmd->command = set_path_name(token);
	cmd->num_args = 2;
	cmd->filename = NULL;
	cmd->args = set_arg_array_quoted(token);
	cmd->next = NULL;
	return (cmd);
}

static char **set_arg_array_quoted(char *token)
{
	char **args = malloc(sizeof(char *) * 2);
	args[0] = set_command(token);
	args[1] = NULL;
	return (args);
}

static char *set_command(char *token)
{
	int i = 0;
	char *cmd;

	while(token && token[i] && !ft_isspace(token[i]))
		i++;
	if(token[i])
		cmd = set_path_name(token);
	else
		cmd = set_path_name(token);
	return (cmd);
}

char *in_quotes(char *input)
{
	char *str = NULL;
	int len = ft_strlen(input);

	str = ft_strnstr(input, "'", len);
	if(str)
		return (str);
	str = ft_strnstr(input, "\"", len);
	if(str)
		return (str);
	return (str);
}

int check_if_quoted(char *input)
{
	int len = ft_strlen(input);

	if(len == 0)
		return (0);
	else if(input[0] == '\'' && input[len-1] == '\'')
		return (1);
	else if(input[0] == '"' && input[len-1] == '"')
		return (1);
	else
		return (0);
}

char *remove_quotes(char *str)
{
	int len = ft_strlen(str);
	char *res = ft_strnmdup(str, 1, len - 1);
	return (res);
}
