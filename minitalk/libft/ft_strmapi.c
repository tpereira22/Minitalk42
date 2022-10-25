/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:08:19 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:12:51 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function ’f’ to each character of the string s.
// Allocates memory to create a new string
// resulting from successive applications of ’f’.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	rtn = (char *)malloc(i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
