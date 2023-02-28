/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/28 15:55:11 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    convert_dec(char *str)
{
    int i;
    char c;
    
    i = 0;
    while (i < 8 && str[i])
    {
        c = c * 2 + str[i] - 48;
        i++;
    }
    ft_putchar(c);
}

void    handler(int signal, siginfo_t *info, void *utp)
{
    (void)utp;
    static char str[8];
    static int i;
    static int remember;
    int a;
    a = info->si_pid;
    if (a != remember)
    {
        i = 0;
        remember = a;
    }
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
    if (i == 8)
    {
        convert_dec(str);
        i = 0;
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