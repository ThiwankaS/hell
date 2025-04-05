#include "../includes/shell.h"

int close_fds(int fd[][2], int limit);
int init_pipes(int fd[][2], int limit);
int wait_for_children(int limit);

int execute(t_shell *mini)
{
	int index = 0, limit = mini->num_cmds;
	t_cmd *current = mini->cmds;
	pid_t pid;
	int fd[limit][2];

	init_pipes(fd, limit);
	while(current)
	{
		if((pid = fork()) == -1)
			syntax_error("Fork fialed");
		else if(pid == 0)
		{
			if(index > 0)
				dup2(fd[index - 1][0], STDIN_FILENO);
			if(current->next)
				dup2(fd[index][1], STDOUT_FILENO);
			close_fds(fd, limit);
			if((execve(current->command, current->args, current->envp)) == -1)
				syntax_error("Command execution failed");
		}
		current = current->next;
		index++;
	}
	close_fds(fd, limit);
	wait_for_children(limit);
	return (0);
}

int init_pipes(int fd[][2], int limit)
{
	int i = 0;

	while(i < limit)
	{
		if((pipe(fd[i])) == -1)
		{
			syntax_error("Pipe creation failed");
		}
		i++;
	}
	return (0);
}

int wait_for_children(int limit)
{
	int i = 0;
	while(i < limit)
	{
		wait(NULL);
		i++;
	}
	return (0);
}

int close_fds(int fd[][2], int limit)
{
	int i = 0;
	while(i < limit)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	return (0);
}
