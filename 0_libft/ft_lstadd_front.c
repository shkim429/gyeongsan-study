/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:39:30 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/11 14:53:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list	*lst = NULL;
	char *str1 = "abc";
	char *str2 = "def";
	ft_lstadd_front(&lst, ft_lstnew(str1));
	ft_lstadd_front(&lst, ft_lstnew(str2));
	while (lst)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}
*/