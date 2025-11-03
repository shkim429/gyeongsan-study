#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int	cnt = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		cnt++;
	}
	return (cnt);
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_list	*n1 = malloc(sizeof(t_list));
	t_list	*n2 = malloc(sizeof(t_list));

	n1->data = "hello";
	n2->data = "world";

	n1->next = n2;
	n2->next = NULL;

	int size = ft_list_size(n1);

	printf("%d\n", size);
}