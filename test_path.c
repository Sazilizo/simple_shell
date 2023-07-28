#include "shell.h"
/**
* test_path - checks whether path is valid
* @path: tokenized path
* @cmd: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *test_path(char **path, char *cmd)
{
	int i = 0;
	char *string;

	while (path[i])
	{
		string = append_path(path[i], cmd);
		if (access(string, F_OK | X_OK) == 0)
			return (string);
		free(string);
		i++;
	}
	return (NULL);
}
