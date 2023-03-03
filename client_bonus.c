/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:07:46 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:10 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	tab(char *t)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		t[i] = '0';
		i++;
	}
}

int	check_pid(char *p)
{
	if (ft_atoi(p) <= 1)
	{
		write (1, "pid not available\n", 18);
		exit (1);
	}
	return (ft_atoi(p));
}

void	convert_ben(unsigned char c, char *p)
{
	int		i;
	char	t[9];
	int		pid;

	pid = check_pid(p);
	tab (t);
	i = -1;
	while (c)
	{
		t[++i] = c % 2 + 48;
		c /= 2;
	}
	i = 7;
	while (i >= 0)
	{
		if (t[i] == '0')
			kill (pid, SIGUSR1);
		else if (t[i] == '1')
			kill (pid, SIGUSR2);
		usleep (250);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 3)
	{
		while (av[2][i])
		{
			convert_ben((unsigned char)av[2][i], av[1]);
			i++;
		}
	}
}
