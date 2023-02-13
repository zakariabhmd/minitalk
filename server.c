/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/12 22:23:20 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void handler(int signal, siginfo_t *info, void *utp)
{
    (void)utp;
    char *str;
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
    printf("bin = %s", str);
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
    {
        pause();
    }
}