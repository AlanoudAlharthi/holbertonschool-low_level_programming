#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit - prints an error message and exits with a code
 * @code: exit code
 * @msg: error message
 * @file: file name (if needed)
 */
void error_exit(int code, const char *msg, const char *file)
{
	if (file)
		dprintf(2, "%s %s\n", msg, file);
	else
		dprintf(2, "%s\n", msg);
	exit(code);
}

/**
 * main - copies the content of one file to another
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, exits on failure with specific codes
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[1024];

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

	while ((r = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		w = write(fd_to, buffer, r);
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

	return (0);
}
