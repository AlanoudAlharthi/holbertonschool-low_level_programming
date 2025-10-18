#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		if (close(fd_from) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(99);
	}

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]);
			if (close(fd_from) == -1)
				dprintf(2, "Error: Can't close fd %d\n", fd_from);
			if (close(fd_to) == -1)
				dprintf(2, "Error: Can't close fd %d\n", fd_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		if (close(fd_from) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_from);
		if (close(fd_to) == -1)
			dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
