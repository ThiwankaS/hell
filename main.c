#include "includes/shell.h"

int main (int ac, char **av)
{
	char *input;
	int status = 0;

	(void)av;
	if(ac == 1)
	{
		while((input = readline("@so_thiwanka > ")))
		{
			add_history(input);
			status = activate_shell(input);
			free(input);
		}
	}
	return (status);
}
