/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:42:46 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:23:04 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns an array 
// of strings obtained by splitting s 
// using the character c as a delimiter.

static char	**ft_free(char **rtn)
{
	int	i;

	if (!rtn)
		return (NULL);
	i = 0;
	while (rtn[i])
	{
		free(rtn[i]);
		rtn[i] = NULL;
		i++;
	}
	free(rtn);
	return (rtn);
}

static int	ft_wordend(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static bool	ft_fill(char **rtn, char const *s, char c)
{
	int	i;
	int	end;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			end = ft_wordend(s, c, i);
			*rtn = ft_calloc(sizeof(**rtn), end - i + 1);
			if (!*rtn)
				return (false);
			ft_memcpy(*rtn, s + i, end - i);
			rtn++;
			i = end - 1;
		}
		i++;
	}
	return (true);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			wordcount++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (wordcount);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		nr_words;

	if (!s || !*s)
	{
		rtn = malloc(sizeof(char *) * 1);
		if (!rtn)
			return (NULL);
		*rtn = NULL;
		return (rtn);
	}
	nr_words = ft_wordcount(s, c);
	rtn = ft_calloc(sizeof(*rtn), nr_words + 1);
	if (!rtn)
		return (NULL);
	if (!ft_fill(rtn, s, c))
		return (ft_free(rtn));
	return (rtn);
}
