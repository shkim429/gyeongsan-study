enum {
	READ,
	WRITE
};

char **cmds[]

pid_t pid;
int fd1[2] = {STDIN_FILENO, STDOUT_FILENO}, next_in = STDIN_FILENO;
int cnt;
int infd, outfd;

fd1[READ] = open("infile")

cnt = 0;
while (*cmds)
{
	if (cmds[1] == NULL)
		fd1[WRITE] = open(~);
	else if (connect_pipe(fd1 + WRITE, &nextin) == false)
		return (1);
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		close(nextin);
		execute_child(*cmds, fd1);
		close_pipe(fd1);
		exit(EXIT_FAILURE);
	}
	close_pipe(fd1);
	update_pipe(fd1, nextin);
	cnt++;
	cmds++;
}
close(fd1);
if (wait_all(n) == false)
	return (1);

connect_pipe(int *curout, int *nextin)
{
	int fd[2];
	if (pipe(fd) < 0)
		return (false);
	*curout = fd[WRITE];
	*nextin = fd[READ];
	return (true);
}

execute_child(char *cmd[], int fd[2])
{
	if (prepare_io(fd) == false)
		return;
	execvp(*cmd, cmd);
}

bool prepare_io(int fd[2])
{
	int in = fd[READ];
	int out = fd[WRITE];

	if (prepare_stdfd(in, STDIN_FILENO) == false)
		return (false);
	if (prepare_stdfd(out, STDOUT_FILENO) == false)
		return (false);
	return (true);
}

bool prepare_stdfd(int fd, int stdfd)
{
	if (fd < 0)
	{
		print_error()
		return (false);
	}
	if (fd != stdfd)
	{
		if (dup2(fd, stdfd) < 0)
			return (false);
		close(fd);
	}
	return (true);
}

close_pipe(int fd[2])
{
	int in = fd[READ];
	int out = fd[WRITE];

	if (in >= 0 && in != STDIN_FILENO)
		close(in);
	if (out >= 0 && out != STDOUT_FILENO)
		close(out);
}

update_pipe(int fd1[2], int *nextin)
{
	fd1[READ] = *nextin;
	fd1[WRITE] = STDOUT_FILENO;
	*nextin = STDIN_FILENO;
}

bool wait_all(int n)
{
	while (n--)
		if (wait(NULL) < 0)
			return (false);
	return (true);
}