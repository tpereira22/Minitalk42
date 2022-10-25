/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:30:05 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:12:21 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function locates the first occurrence 
// of the null-terminated string needle in thestring haystack,
// where not more than len characters are searched.

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*hay;

	hay = (char *)haystack;
	if (needle[0] == '\0')
		return (hay);
	if (hay[0] == '\0')
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		k = i;
		while (hay[k] == needle[j] && k < len)
		{
			k++;
			j++;
			if (needle[j] == '\0')
				return (hay + i);
		}
		i++;
	}
	return (0);
}
