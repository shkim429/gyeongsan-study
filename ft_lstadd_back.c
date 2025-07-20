/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:24:53 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/11 18:38:18 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	return (*lst);
}
/*
int main()
{
	t_list *lst = NULL;
	char *str1 = "abc";
	char *str2 = "def";

	t_list *node1 = ft_lstnew(str1);
	t_list *node2 = ft_lstnew(str2);
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;

	}
}
*/