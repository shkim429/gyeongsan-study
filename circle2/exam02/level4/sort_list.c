#include "ft_list.h"
#include <stdlib.h>

t_list *sort_list(t_list * list, int (*cmp)(int, int))
{
	t_list *start;
	int tmp = 0;
	start = list;
	while (list != NULL& list->next != NULL)
	{
		if ((*cmp)(list->data, list->next->data) == 0)
		{
			tmp = list->data;
			list->data = list->next->data;
			list->next->data = tmp;
			list = start;
		}
		else
			list = list->next;
	}
	return (start);
}