/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:52:08 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/11 14:39:38 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/09 22:07:35 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
<<<<<<< HEAD
	return (new);
}
/*
int main()
{
	char *str = "abc";
	t_list *node = ft_lstnew(str);
	printf("%s\n", (char *)node->next);
	printf("%s", (char *)node->content);
}
*/
=======
}
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
