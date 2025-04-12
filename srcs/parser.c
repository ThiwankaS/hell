#include "../includes/shell.h"

void expand(t_shell *mini, t_list *list);
int get_num_args(char *token);
char *set_path_name(char *token);
static void get_args(char **args, char *token, int size);
static char **set_arg_array_smpl(int num_args, char *token);
t_cmd *handel_pipe(t_list *current);

int parse_and_expand(t_shell *mini)
{
	expand(mini, mini->tokens);
	return (0);
}

void expand(t_shell *mini, t_list *list)
{
	t_list *current = list;
	t_cmd *cmd = NULL;

	while(current)
	{
		if(check_if_quoted(current->token))
			cmd = handle_quoted(current->token);
		else if(ft_strchr(current->token, '>'))
			cmd = handel_output(current->token);
		else
			cmd = handel_pipe(current);
		mini->cmds = list_add_command(mini->cmds, cmd);
		cmd = NULL;
		mini->num_cmds++;
		current = current->next;
	}
}

t_cmd *handel_pipe(t_list *current)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
			return (NULL);
	cmd->type = SMPL_CMD;
	cmd->command = set_path_name(current->token);
	cmd->filename = NULL;
	cmd->num_args = get_num_args(current->token);
	cmd->args = set_arg_array_smpl(cmd->num_args, current->token);
	cmd->next = NULL;
	return (cmd);
}

static char **set_arg_array_smpl(int num_args, char *token)
{
	char **args = malloc(sizeof(char*) * (num_args + 1));
	if(!args)
		return (NULL);
	args[0] = set_path_name(token);
	if(num_args > 1)
		get_args(args, token, num_args);
	args[num_args] = NULL;
	return (args);
}

char *set_path_name(char *token)
{
	char *path = ft_strdup("/bin/");
	char *cmd =  get_command(token);
	char *command = ft_strjoin(path, cmd);
	free(path);
	free(cmd);
	return (command);
}

char *get_command(char *token)
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

static void get_args(char **args, char *token, int size)
{
	int i = 0, k = 0, start = 0, step = 1;
	while(token && token[i] && token[i] != ' ')
		i++;
	while(step < size)
	{
		while(token && token[i] && token[i] == ' ')
			i++;
		start = i;
		while(token && token[i] && token[i] != ' ')
			i++;
		args[step] = malloc(sizeof(char) * (i - start + 1));
		k = 0;
		while(token && token[k + start] && (k + start) < i)
		{
			args[step][k] = token[k + start];
			k++;
		}
		args[step][k] = '\0';
		step++;
	}
}
