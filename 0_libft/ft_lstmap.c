/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 01:03:45 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/14 01:22:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	*f(void *content)
// {
// 	char	*str;
// 	char	*str_copy;

// 	str = (char *)ft_strdup(content);
// 	str_copy = str;
// 	while (*str_copy != '\0')
// 	{
// 		if (*str_copy >= 'a' && *str_copy <= 'z')
// 			*str_copy = *str_copy - 32;
// 		str_copy++;
// 	}
// 	return (str);
// }
// void	del(void *content)
// {
// 	(void)content;
// 	// free(content);
// }
// int main()
// {
// 	t_list *node1 = ft_lstnew((void *)1);
// 	t_list *node2 = ft_lstnew(strdup("def"));
// 	t_list *node3 = ft_lstnew(strdup("ghi"));

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list *lst = node1;
// 	t_list *tmp = lst;
// 	while (tmp != NULL)
// 	{
// 		printf("%s ", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// 	 t_list *new_lst = ft_lstmap(lst, f, del);
// 	 while (new_lst != NULL)
// 	 {
// 		printf("%s ", (char *)new_lst->content);
// 		new_lst = new_lst->next;
// 	 }
// }
