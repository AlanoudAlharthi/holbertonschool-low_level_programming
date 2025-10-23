#include "hash_tables.h"

/**
 * update_value - Updates the value of an existing key
 * @node: the node to update
 * @value: new value to assign
 *
 * Return: 1 on success, 0 on failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *value_copy;

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	free(node->value);
	node->value = value_copy;
	return (1);
}

/**
 * add_node_to_table - Adds a new node at the beginning of the list
 * @ht: hash table
 * @key: key string
 * @value: value string
 * @index: index in hash table array
 *
 * Return: 1 on success, 0 on failure
 */
int add_node_to_table(hash_table_t *ht, const char *key,
		      const char *value, unsigned long int index)
{
	hash_node_t *new_node;

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

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: the hash table
 * @key: the key (cannot be empty)
 * @value: the value to store
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (update_value(current, value));
		current = current->next;
	}

	return (add_node_to_table(ht, key, value, index));
}
