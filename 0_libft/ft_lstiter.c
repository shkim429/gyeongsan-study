/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:39:05 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/12 01:02:10 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	f(void *content)
{
	char	*str;
	
	str = (char *)content;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}

int main()
{
	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(strdup("abc"));
	t_list *node2 = ft_lstnew(strdup("def"));

	node1->next = node2;
	lst = node1;
	
	t_list *tmp = lst;
	
	while (tmp != NULL)
	{
		printf("%s ", (char *)tmp->content);
		tmp = tmp->next;
	}

	printf("\n");
	
	ft_lstiter(lst, f);
	
	while (lst != NULL)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}
*/