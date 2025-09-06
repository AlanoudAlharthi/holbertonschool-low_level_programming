/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* move to the end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* copy at most n characters from src */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* add null terminator */
	dest[i] = '\0';

	return (dest);
}
