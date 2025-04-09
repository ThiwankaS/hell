#include "../includes/shell.h"

/**
 * char *str = "this line will write to the file";
	int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
	int len = ft_strlen(str);
	printf("len : %d\n", len);
	write(fd, str, len);
	close(fd);
	return (0);
*/

t_cmd *handel_output(char *token)
{
	/**
	 * example of the command format
	 * echo "the string need to write in to the file" > file.txt
	*/
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		return (NULL);
	char **args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("/bin/echo");
	args[1] = ft_strdup("Here is the new string");
	args[2] = NULL;
	printf("token : %s\n", token);
	cmd->type = OPRD_CMD;
	cmd->command = ft_strdup("/bin/echo");
	cmd->args = args;
	cmd->num_args = 3;
	cmd->next = NULL;
	return (cmd);
}
