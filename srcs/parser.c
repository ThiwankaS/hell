#include "../includes/shell.h"

void expand(t_shell *mini, t_list *list);
static int get_num_args2(char *token);
static void get_args(char **args, char *token, int size);
static char *get_command(char *token);
static char *set_path_name(char *token);
static char **set_arg_array(int num_args, char *token);
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
		if(ft_strchr(current->token, '>'))
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
	cmd->num_args = get_num_args2(current->token);
	cmd->args = set_arg_array(cmd->num_args, current->token);
	cmd->next = NULL;
	return (cmd);
}

static char **set_arg_array(int num_args, char *token)
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

static char *set_path_name(char *token)
{
	char *path = ft_strdup("/bin/");
	char *command = ft_strjoin(path, get_command(token));
	free(path);
	return (command);
}

static char *get_command(char *token)
{
	int i = 0, j = 0;
	char *command;

	while(token && token[i])
	{
		if(token[i] == ' ')
		{
			command = malloc(sizeof(char)*(i + 1));
			if(!command)
				return (NULL);
			while(token && token[j] && j < i)
			{
				command[j] = token[j];
				j++;
			}
			command[j] = '\0';
			return (command);
		}
		i++;
	}
	if(token[i] == '\0')
		return (token);
	return (NULL);
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

static int get_num_args2(char *token)
{
	int i = 0, count = 1, flag = 0;
	while(token && token[i])
	{
		if(token[i] == ' ' && !flag)
		{
			count++;
			flag = 1;
		}
		else if(token[i] != ' ' && flag)
			flag = 0;
		i++;
	}
	return (count);
}
