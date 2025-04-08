#include "../includes/shell.h"

int activate_shell(char *input, char **envp);

int activate_shell(char *input, char **envp)
{
	int status = 0;
	t_shell *mini = malloc(sizeof(t_shell));
	if(!mini)
		return (1);
	mini->num_cmds = 0;
	mini->tokens = NULL;
	mini->cmds = NULL;
	mini->envp = envp;

	if((status = input_validate(&input)))
		return (clear_and_exit(mini, status));
	if((status = extract_tokens(&mini->tokens, input)))
		return (clear_and_exit(mini, status));
	if((status = parse_and_expand(mini )))
		return (clear_and_exit(mini, status));
	if((status = execute(mini)))
		return (clear_and_exit(mini, status));
	return (clear_and_exit(mini, status));
}
