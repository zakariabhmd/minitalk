/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/03/08 23:53:21 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	convert_dec(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (i < 8)
	{
		c = c * 2 + str[i] - 48;
		i++;
	}
	ft_putchar(c);
}

void	handler(int signal, siginfo_t *info, void *utp)
{
	static char	str[8];
	static int	i;
	static int	remember;
	int			a;

	(void)utp;
	a = info->si_pid;
	if (a != remember)
	{
		i = 0;
		remember = a;
	}
	if (signal == SIGUSR1)
		str[i++] = '0';
	if (signal == SIGUSR2)
		str[i++] = '1';
	if (i == 8)
	{
		convert_dec(str);
		kill(info->si_pid,SIGUSR1);
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	creminal;

	creminal.sa_sigaction = handler;
	creminal.sa_flags = 0;
	pid = getpid();
	ft_putnbr(pid);
	sigaction(SIGUSR1, &creminal, NULL);
	sigaction(SIGUSR2, &creminal, NULL);
	write(1, "\n", 1);
	while (1)
		;
}
