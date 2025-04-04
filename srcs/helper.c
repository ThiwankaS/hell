#include "../includes/shell.h"

int activate_shell(char *input);
void print_cmd(t_cmd *cmd);

int activate_shell(char *input)
{
	int status = 0;
	t_shell *mini = malloc(sizeof(t_shell));
	if(!mini)
		return (1);
	mini->tokens = NULL;
	mini->cmds = NULL;
	if((status = input_validate(input)))
		return (1);
	if((status = extract_tokens(&mini->tokens, input)))
		return (1);
	if((status = parse_and_expand(mini)))
		return (1);
	if((status = execute(mini)))
		return (1);
	if((status = clear_and_exit(mini)))
		return (1);
	return (status);
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
