/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:34:16 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/11 18:29:26 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int main()
{
	t_list *lst = NULL;
	char *str1 = "abc";
	char *str2 = "def";
	ft_lstadd_front(&lst, ft_lstnew(str1));
	ft_lstadd_front(&lst, ft_lstnew(str2));

	t_list *last = ft_lstlast(lst);
	printf("last의 값 = %s\n", (char *)last->content);
	
}
*/