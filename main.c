#include "includes/shell.h"

volatile sig_atomic_t sig = 0;

int main (int ac, char **av, char **envp)
{
	char *input;
	int status = 0;

	(void)av;
	if(ac == 1)
	{
		while((input = readline("@so_thiwanka > ")))
		{
			init_sig();
			add_history(input);
			if(ft_strncmp(input, "exit", 5) == 0)
				break;
			status = activate_shell(input, envp);
			free(input);
		}
		if(input)
			free(input);
	}
	return (status);
}
