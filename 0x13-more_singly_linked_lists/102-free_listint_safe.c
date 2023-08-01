#include "lists.h"

/**
 * free_listint_safe - Frees a linked list of integers.
 * @h: Pointer to the pointer to the head node of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *tortoise, *hare, *temp;

	if (h == NULL || *h == NULL)
		return (0);
	tortoise = *h;
	hare = (*h)->next;
	while (tortoise && hare && hare->next)
	{
		if (tortoise == hare)
		{
			size++;
			tortoise = tortoise->next;
			while (tortoise != hare)
			{
				temp = tortoise;
				tortoise = tortoise->next;
				free(temp);
				size++;
			}
			*h = NULL;
			return (size);
		}
		size++;
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	size++;
	while (*h)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
	}
	*h = NULL;
	return (size);
}
