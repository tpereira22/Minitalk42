/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:46:58 by timartin          #+#    #+#             */
/*   Updated: 2022/04/07 19:18:15 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns a string 
// representing the integer received as an argument.
// Handles negative numbers.

static char	write_neg(char *s, int neg)
{
	if (neg == 1)
	{
		s[0] = '-';
		return (*s);
	}
	else if (neg == 2)
	{
		s[0] = '-';
		s[1] = '2';
		return (*s);
	}
	else
		return (*s);
}

static int	num_len(int digits, int len)
{
	int	len_final;

	len_final = len;
	if (digits == 0)
		return (1);
	while (digits > 0)
	{
		digits = digits / 10;
		len_final++;
	}
	return (len_final);
}

static int	is_neg(int *p_digits, int *p_len, int *p_n)
{
	int	neg;
	int	dig;

	dig = *p_digits;
	neg = 0;
	if (dig == INT_MIN)
	{
		*p_len = 2;
		*p_digits = 147483648;
		*p_n = 147483648;
		return (neg + 2);
	}
	else if (dig < 0)
	{
		*p_len = 1;
		*p_digits = dig * (-1);
		*p_n = dig * (-1);
		return (neg + 1);
	}
	else
		return (neg);
}

char	*ft_itoa(int n)
{
	char	*rtn;
	int		digits;
	int		len;
	int		neg;
	char	c;

	digits = n;
	len = 0;
	neg = is_neg(&digits, &len, &n);
	len = num_len(digits, len);
	rtn = malloc((len + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	*rtn = write_neg(rtn, neg);
	rtn[len] = '\0';
	while (len > 0)
	{
		if ((neg == 1 && len == 1) || (neg == 2 && len == 2))
			break ;
		c = n % 10 + 48;
		rtn[len - 1] = c;
		n = n / 10;
		len--;
	}
	return (rtn);
}
