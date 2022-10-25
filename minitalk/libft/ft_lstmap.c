/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:25:59 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:17:56 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates lst and applies the 
// function f on the content of each node.
// Creates a new list resulting of the 
// successive applications of the function f.
// The ’del’ function is used to delete the content of a node if needed. 

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*save;

	if (!lst)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		save = ft_lstnew(f(lst->content));
		if (!save)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, save);
		lst = lst->next;
	}
	return (newlst);
}
