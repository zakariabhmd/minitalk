/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:07:46 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/10 18:19:05 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void convert_ben(char c, char *p)
{   
    int i;
    char t[8];
	int pid;
    
    i = 0;
    while (c)
    {
        t[i] = c % 2 + 48;
		c /= 2;
		i++;   
    }
	i = 7;
	pid = ft_atoi(p);
	while(t[i])
	{
		if (t[i] == '0')
			kill(pid, SIGUS1);
		else if (t[i] == '1')
			kill(pid, SIGUS2);
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
            convert_ben(av[2][i], av[1]);
        }
    }
}