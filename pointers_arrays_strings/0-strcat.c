/**
 * _strcat - concatenates two strings
 * @dest: pointer to destination string
 * @src: pointer to source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* move i to the end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* copy src to dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* add null terminator at the end */
	dest[i] = '\0';

	return (dest);
}
