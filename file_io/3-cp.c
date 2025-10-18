#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit - print error message and exit with code
 * @code: exit code
 * @msg: error message
 * @file: file name
 */
void error_exit(int code, const char *msg, const char *file)
{
	if (file)
		dprintf(2, "%s %s\n", msg, file); // stderr
	else
		dprintf(2, "%s\n", msg);

	exit(code); // exit, don't print code to stdout
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to", NULL);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit(99, "Error: Can't write to", argv[2]);
	}

	while ((r = read(fd_from, buf, sizeof(buf))) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit(99, "Error: Can't write to", argv[2]);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit(98, "Error: Can't read from file", argv[1]);
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd", argv[1]);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd", argv[2]);

	return (0); // do not print the exit code
}
