/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:15:21 by timartin          #+#    #+#             */
/*   Updated: 2022/03/23 17:37:36 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cpy;

	cpy = *lst;
	while (cpy)
	{
		temp = cpy->next;
		ft_lstdelone(cpy, del);
		cpy = temp;
	}
	*lst = NULL;
}
