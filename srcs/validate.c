#include "../includes/shell.h"

int input_validate(char **input);
static void input_preprocess(char **input);
static int check_properly_enclosed(char *input);
static int check_special_character(char *input);
static char *remove_comments(char *input);

int input_validate(char **input)
{
	input_preprocess(input);
	if(check_properly_enclosed(*input))
		return (syntax_error(*input ,"Sysntax Error : unclosed quotes !"));
	if(check_special_character(*input))
		return (syntax_error(*input ,"Sysntax Error : unrecognized characters !"));
	return (0);
}

static void input_preprocess(char **input)
{
	char *trimmed;

	trimmed = ft_strtrim(remove_comments(*input), " \f\n\r\t\v");
	*input = ft_strdup(trimmed);
	free(trimmed);
}

static char *remove_comments(char *input)
{
	char *stream;

	stream = ft_strchr(input,'#');
	if(stream)
	{
		stream = ft_strnmdup(input, 0, (stream - input));
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
