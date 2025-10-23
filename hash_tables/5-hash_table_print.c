#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: the hash table
 *
 * Format: {'key': 'value', 'key': 'value', ...}
 * Prints in the order they appear in the array and in the linked lists
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int first = 1;

	if (!ht)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first = 0;
			node = node->next;
		}
	}

	printf("}\n");
}
