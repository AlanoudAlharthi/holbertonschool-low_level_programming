#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_exit - Prints an error message and exits with a given code
 * @code: Exit code
 * @msg: Error message format
 * @arg: Argument to include in the message (can be NULL)
 */
void error_exit(int code, const char *msg, const char *arg)
{
	if (arg)
		dprintf(STDERR_FILENO, msg, arg);
	else
		dprintf(STDERR_FILENO, "%s", msg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, exits with error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		if (close(fd_from) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	while (1)
	{
		n_read = read(fd_from, buffer, sizeof(buffer));
		if (n_read == -1)
		{
			if (close(fd_from) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			if (close(fd_to) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);
		}

		if (n_read == 0)
			break;

		n_written = write(fd_to, buffer, n_read);
		if (n_written != n_read)
		{
			if (close(fd_from) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			if (close(fd_to) == -1)
				dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
		}
	}

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", argv[1]);
	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", argv[2]);

	return (0);
}
