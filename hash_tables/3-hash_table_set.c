#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: the hash table
 * @key: the key (cannot be an empty string)
 * @value: the value associated with the key (duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	/* check if the key already exists, update the value */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);

			free(current->value);
			current->value = value_copy;
			return (1);
		}
		current = current->next;
	}

	/* create a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* add the new node at the beginning of the list (handle collisions) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
