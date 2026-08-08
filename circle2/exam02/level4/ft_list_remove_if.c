#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;

	t_list *list = *begin_list;

	if (cmp(list->data, data_ref) = 0)
	{
		*begin_list = list->next;
		free(list);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		list = *begin_list;
		ft_list_remove_if(&list->next, data_ref, cmp);
	}
}