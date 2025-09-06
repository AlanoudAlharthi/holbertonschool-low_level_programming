#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to be modified
 *
 * Return: pointer to the resulting string
 *
 * Description: Words are separated by space, tabulation, new line,
 *              ,, ;, ., !, ?, ", (, ), {, and }
 */
char *cap_string(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32; /* Capitalize first character if needed */

	i = 1;
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n' ||
		     str[i - 1] == ',' || str[i - 1] == ';' || str[i - 1] == '.' ||
		     str[i - 1] == '!' || str[i - 1] == '?' || str[i - 1] == '"' ||
		     str[i - 1] == '(' || str[i - 1] == ')' || str[i - 1] == '{' ||
		     str[i - 1] == '}') &&
		    (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32; /* Capitalize the first letter after separator */
		}
		i++;
	}
	return (str);
}
