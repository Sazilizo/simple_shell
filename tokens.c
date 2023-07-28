#include "shell.h"
/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **tokenizer(char *line)
{
	char *buffer = NULL, *delim = " :\t\r\n",*bufp = NULL, *token = NULL;
	char **tokens = NULL;
	int token_size = 1;
	size_t i = 0, flag = 0;

	buffer = _strdup(line);
	if (!buffer)
		return (NULL);
	bufp = buffer;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		{
			token_size++;
			flag = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (token_size + 1));
	if (tokens == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	while (token)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = '\0';
	free(buffer);
	return (tokens);
}

