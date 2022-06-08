/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afenzl <afenzl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:23:56 by afenzl            #+#    #+#             */
/*   Updated: 2022/04/13 13:44:44 by afenzl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	if (lst->content == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->content == NULL)
		{
			ft_lstiter(list, del);
			free(list);
			return (NULL);
		}
		ft_lstadd_back(&list, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (list);
}
