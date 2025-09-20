#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s && s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - copies a string to a new buffer
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (dest);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog_t struct, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_d;
	int len_name, len_owner;

	new_d = malloc(sizeof(dog_t));
	if (new_d == NULL)
		return (NULL);

	len_name = _strlen(name);
	len_owner = _strlen(owner);

	new_d->name = malloc(sizeof(char) * (len_name + 1));
	if (new_d->name == NULL)
	{
		free(new_d);
		return (NULL);
	}
	new_d->owner = malloc(sizeof(char) * (len_owner + 1));
	if (new_d->owner == NULL)
	{
		free(new_d->name);
		free(new_d);
		return (NULL);
	}

	_strcpy(new_d->name, name);
	_strcpy(new_d->owner, owner);
	new_d->age = age;

	return (new_d);
}
