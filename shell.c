#include "shell.h"
/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/
struct flags flags;
struct info info;
struct builtin builtin;
int main(int ac, char **av, char *env[])
{
	char *line = NULL, *pathcmd = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **cmd = NULL, **paths = NULL;
	(void)env, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffers(cmd);
		free_buffers(paths);
		free(pathcmd);
		print_prompt();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		cmd = tokenizer(line);
		if (cmd == NULL || **cmd == '\0' || *cmd == NULL)
			continue;
		if (check_builtIn(cmd, line))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcmd = test_path(paths, cmd[0]);
		if (!pathcmd)
			perror(av[0]);
		else
			execute_cmd(pathcmd, cmd);
	}
	if (flags.interactive && linesize < 0)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
