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

t_cmd *handel_output(t_cmd *cmd, char *token)
{
	/**
	 * example of the command format
	 * echo "the string need to write in to the file" > file.txt
	*/
	char **args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("bin\echo");
	args[1] = ft_strdup("this is the testing string");
	args[2] = NULL;
	printf("token : %s\n", token);
	cmd->command = ft_strdup("bin\echo");
	cmd->args = args;
	return (cmd);
}
