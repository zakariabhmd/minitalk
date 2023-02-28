/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:07:46 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/28 15:55:28 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void convert_ben(unsigned char c, char *p)
{   
    int i;
    char t[9];
	int pid;
    
    i = 0;
    while(i < 8)
    {
        t[i] = '0';
        i++;
    }
    i = 0;
    while (c)
    {
        t[i] = c % 2 + 48;
		c /= 2;
		i++;   
    }
	i = 7;
	pid = ft_atoi(p);
    if (pid == -1 || pid == 0 || pid == 1)
    {
        write(1, "pid not available\n", 18);
        exit(1);
    }
	while(i >= 0)
	{
		if (t[i] == '0')
			kill(pid, SIGUSR1);
		else if (t[i] == '1')
			kill(pid, SIGUSR2);
        usleep(250);
		i--;
	}
}

int main(int ac, char **av)
{
    int i;
    
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