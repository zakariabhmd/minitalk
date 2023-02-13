/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/13 15:09:50 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
110000
void    convert_dec(char *str)
{
    int i;
    char c;
    
    i = 0;
    while (str[i] != '\0')
    {
        c *= 2 + str[i++];
    }
}

void    handler(int signal, siginfo_t *info, void *utp)
{
    (void)utp;
    static char str[8];
    int i=0;
    if (signal == SIGUSR1)
    {
        str[i] = '0';
        i++;   
    }
    if (signal == SIGUSR2)
    {
        str[i] = '1';
        i++;
    }
    if (i < 8)
    {
        convert_dec(str);
    }
}

int main()
{
    int pid;
    struct sigaction creminal;
    
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