/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:38:52 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/13 04:19:02 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	free(content);
}

int main()
{
	t_list *lst = NULL;
	char *str1 = strdup("abc");
	char *str2 = strdup("def");

	t_list *node1 = ft_lstnew(str1);
	t_list *node2 = ft_lstnew(str2);
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);

	t_list *tmp = lst;
	while (tmp != NULL)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	node1->next = NULL;
	ft_lstdelone(node2, del);
	while (lst != NULL)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}
*/

