/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:01:30 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:13:49 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns a new string,
// which is the result of the concatenation of s1 and s2.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		j;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	rtn = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		rtn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		rtn[i] = s2[j];
		i++;
		j++;
	}
	rtn[i] = '\0';
	return (rtn);
}
