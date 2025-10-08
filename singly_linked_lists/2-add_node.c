#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);

	/* حساب طول النص */
	while (str[len])
		len++;

	/* حجز مساحة للـ node الجديدة */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* نسخ النص باستخدام strdup */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = len;
	new_node->next = *head; /* تربط node الجديدة بالرأس القديم */
	*head = new_node;       /* تحديث الرأس ليشير للعقدة الجديدة */

	return (new_node);
}
