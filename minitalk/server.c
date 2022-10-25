/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:13:46 by timartin          #+#    #+#             */
/*   Updated: 2022/10/24 17:11:49 by timartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int	g_i = 0;

int	ft_power(int nb, int p)
{
	int	result;

	result = 1;
	while (p != 0)
	{
		result *= nb;
		p--;
	}
	return (result);
}

int	convert_dec(char *str)
{
	int	i;
	int	dec;
	int	res;
	int	bit;

	bit = ft_atoi(str);
	dec = 0;
	res = 0;
	i = 0;
	while (bit != 0)
	{
		res = bit % 10;
		bit /= 10;
		dec += res * ft_power(2, i);
		i++;
	}
	return (dec);
}

void	handle_str(int sign, siginfo_t *info, void *context)
{
	char	str[9];
	int		final_char;
	static pid_t	client__pid;

	(void)context;
	client__pid = 0;
	if(!client__pid)
		client__pid = info->si_pid;
	if (sign == 10)
		str[g_i++] = '0';
	else if (sign == 12)
		str[g_i++] = '1';
	if (g_i == 8)
	{
		str[g_i] = 0;
		final_char = convert_dec(str);
		ft_putchar_fd(final_char, 1);
		if (final_char == 10)
			kill(client__pid, SIGUSR2);
		kill(client__pid, SIGUSR1);
		g_i = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID -> ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd(10, 1);
	s_sigaction.sa_sigaction = handle_str;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		;
}
