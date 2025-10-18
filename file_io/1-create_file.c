#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - creates a file and writes text_content into it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0, written;

	if (!filename)
		return (-1);

	if (text_content)
	{
		/* Calculate length of text_content manually */
		while (text_content[len])
			len++;
	}

	/* Open file with rw------- permissions, truncate if it exists */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		written = write(fd, text_content, len);
		if (written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
