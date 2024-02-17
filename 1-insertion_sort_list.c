#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Prints a list of integers
 *
 * @list: The array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list)
	{
		curr = *list;
		while (curr)
		{
			while (curr->next && (curr->n > curr->next->n))
			{
				temp = curr->next;
				curr->next = temp->next;
				temp->prev = curr->prev;

				if (curr->prev)
					curr->prev->next = temp;

				if (temp->next)
					temp->next->prev = curr;

				curr->prev = temp;
				temp->next = curr;

				if (temp->prev)
					curr = temp->prev;
				else
					*list = temp;

				print_list(*list);
			}
			curr = curr->next;
		}
	}
}
