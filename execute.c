#include "shell.h"

/**
 * execute_cmd - executes commands entered by users
 *@cm: command
 *@cmd:vector array of pointers to commands
 * Return: 0
 */
void execute_cmd(char *cm, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cm);
	if (child_pid == 0)
	{
		execve(cm, cmd, env);
		perror(cm);
		free(cm);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
