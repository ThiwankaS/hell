#include "../includes/shell.h"

int execute(t_shell *mini)
{
	t_cmd *current = mini->cmds;
	pid_t pid;
	while(current)
	{
		if((pid = fork()) == -1)
			syntax_error("Fork fialed");
		else if(pid == 0)
		{
			if((execve(current->command, current->args, current->envp)) == -1)
				syntax_error("Command execution failed");
		}
		current = current->next;
	}
	wait(NULL);
	return (0);
}
