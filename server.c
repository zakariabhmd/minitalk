/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/11 17:43:53 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void handler(int signal, siginfo_t *info, void *utp)
{
    (void)utp;
    if (signal == SIGUSR1)
    {
        write (1, "salamo\n", 7);
    }
    if (signal == SIGUSR2)
    {
        write (1, "alaykom\n", 8);
    }
}

int main()
{
    int pid;
    struct sigaction creminal;
    
    creminal.sa_sigaction = handler;
    creminal.sa_flags = SA_SIGINFO;
    pid = getpid();
    ft_putnbr(pid);
    sigaction(SIGUSR1, &creminal, NULL);
    sigaction(SIGUSR2, &creminal, NULL);
    write(1, "\n", 1);
    while (1)
        ;
}