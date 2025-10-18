#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/**
 * main - copies content of a file to another file
 * @ac: number of arguments
 * @av: arguments array
 *
 * Return: 0 on success, exits with code on error
 */
int main(int ac, char **av)
{
    int fd_from, fd_to;
    ssize_t r_bytes, w_bytes;
    char buffer[1024];

    if (ac != 3)
    {
        dprintf(STDOUT_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    fd_from = open(av[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", av[1]);
        exit(98);
    }

    fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDOUT_FILENO, "Error: Can't write to %s\n", av[2]);
        close(fd_from);
        exit(99);
    }

    while ((r_bytes = read(fd_from, buffer, 1024)) > 0)
    {
        w_bytes = write(fd_to, buffer, r_bytes);
        if (w_bytes != r_bytes)
        {
            dprintf(STDOUT_FILENO, "Error: Can't write to %s\n", av[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (r_bytes == -1)
    {
        dprintf(STDOUT_FILENO, "Error: Can't read from file %s\n", av[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    if (close(fd_from) == -1)
    {
        dprintf(STDOUT_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1)
    {
        dprintf(STDOUT_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}
