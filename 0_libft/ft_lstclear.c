/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:49:23 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/12 00:38:42 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
void	del(void *content)
{
	free(content);
}
int main()
{
	t_list *node1 = ft_lstnew(strdup("abc"));
	t_list *node2 = ft_lstnew(strdup("def"));
	
	node1->next = node2;
	
	t_list	*lst = node1;
	t_list *tmp = lst;

	while (tmp != NULL)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	
	ft_lstclear(&lst, del);

	while (lst != NULL)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}
*/