/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:39:21 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 18:50:13 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns a substring from the string.
// The substring begins at index ’start’ and is of maximum size ’len’.

static size_t	real_len(char const *s, size_t start, size_t *p_len)
{
	size_t	slen;
	size_t	rlen;

	slen = ft_strlen(s);
	if (*p_len > slen - start)
	{
		rlen = slen - start;
		*p_len = rlen;
	}
	else if (start > slen)
		*p_len = 0;
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	rlen;

	if (!s)
		return (NULL);
	rlen = real_len(s, start, &len);
	dest = (char *)malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	if (start <= rlen)
	{
		while (len--)
		{
			dest[i] = s[start];
			i++;
			start++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
