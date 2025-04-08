#include "../includes/shell.h"

int clear_commands(t_cmd *cmds);
int clear_tokens(t_list *tokens);
int clear_array(char **array);

int clear_and_exit(t_shell *mini, int status)
{
	clear_commands(mini->cmds);
	clear_tokens(mini->tokens);
	free(mini);
	return (status);
}

int clear_commands(t_cmd *cmds)
{
	t_cmd *current = cmds, *cmd;
	while(current)
	{
		cmd = current;
		current = current->next;
		free(cmd->command);
		clear_array(cmd->args);
		free(cmd);
	}
	cmds = NULL;
	return (0);
}
int clear_tokens(t_list *tokens)
{
	t_list *current = tokens, *next;
	while(current)
	{
		next = current->next;
		free(current->token);
		free(current);
		current = next;
	}
	tokens = NULL;
	return (0);
}

int clear_array(char **array)
{
	int i = 0;
	while(array && array[i])
	{
		if(array[i])
			free(array[i]);
		i++;
	}
	if(array)
		free(array);
	return (0);
}
