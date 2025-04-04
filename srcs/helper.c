#include "../includes/shell.h"

int activate_shell(char *input);

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
