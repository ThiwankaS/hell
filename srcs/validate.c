#include "../includes/shell.h"

int input_validate(char **input);
char *in_quotes(char *input);
static void input_preprocess(char **input);
static int check_properly_enclosed(char *input);
static int check_special_character(char *input);
static int check_if_quoted(char *input);
static char *remove_comments(char *input);

int input_validate(char **input)
{
	input_preprocess(input);
	if(check_properly_enclosed(*input))
		return (syntax_error("Sysntax Error : unclosed quotes !"));
	if(check_if_quoted(*input))
		return (syntax_error("Sysntax Error : command is quoted"));
	if(check_special_character(*input))
		return (syntax_error("Sysntax Error : unrecognized characters !"));
	return (0);
}

static void input_preprocess(char **input)
{
	char *str;

	str = ft_strtrim(remove_comments(*input), " \f\n\r\t\v");
	*input = ft_strdup(str);
	free(str);
}

static char *remove_comments(char *input)
{
	char *stream;

	stream = ft_strchr(input,'#');
	if(stream)
	{
		stream = ft_strndup(input, (stream - input));
		free(input);
		return (stream);
	}
	return (input);
}

static int check_properly_enclosed(char *input)
{
	int in_single_quotes = 0, in_double_quotes = 0, i = 0;

	while(input && input[i])
	{
		if(input[i] == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		if(input[i] == '"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		i++;
	}
	return (in_single_quotes || in_double_quotes);
}

static int check_special_character(char *input)
{
	int i = 0;
	char *special_chars = "\\&;,{()}", *str;

	str = in_quotes(input);
	while(special_chars[i])
	{
		if(ft_strchr(input, special_chars[i]))
		{
			if(!str)
				return (1);
			if(str && !ft_strchr(str, special_chars[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

char *in_quotes(char *input)
{
	char *str = NULL;
	int len = ft_strlen(input);

	str = ft_strnstr(input, "'", len);
	if(str)
		return (str);
	str = ft_strnstr(input, "\"", len);
	if(str)
		return (str);
	return (str);
}

static int check_if_quoted(char *input)
{
	int len = ft_strlen(input);

	if(input[0] == '\'' && input[len-1] == '\'')
		return (1);
	else if(input[0] == '"' && input[len-1] == '"')
		return (1);
	else
		return (0);
}
