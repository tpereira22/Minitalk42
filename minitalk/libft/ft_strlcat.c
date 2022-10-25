/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:07:49 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:13:27 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function appends string src to the end of dst.
// It will append at most dstsize - strlen(dst) - 1 characters.
// Does not handle overlap.

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	while (dest[i])
		i++;
	destlen = i;
	srclen = ft_strlen(src);
	j = 0;
	if (size > 0 && destlen < size - 1)
	{
		while (src[j] && destlen + j < size - 1)
		{
			dest[i] = src[j];
			j++;
			i++;
		}
		dest[i] = '\0';
	}
	if (destlen >= size)
		return (srclen + size);
	return (destlen + srclen);
}
