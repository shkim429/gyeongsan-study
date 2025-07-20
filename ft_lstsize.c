/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:05:29 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/11 15:33:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
/*
int main()
{
	t_list *lst = NULL;
	char *str1 = "abc";
	char *str2 = "def";
	ft_lstadd_front(&lst,ft_lstnew(str1));
	ft_lstadd_front(&lst, ft_lstnew(str2));
	
	printf("%d", ft_lstsize(lst));
	
}*/