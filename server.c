/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbabahmi <zbabahmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:08:17 by zbabahmi          #+#    #+#             */
/*   Updated: 2023/02/13 19:16:57 by zbabahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char    convert_dec(char *str)
{
    int i;
    int index;
    int result;
    int vlu;
    int car;
    
    car = 0;
    vlu = 0;
    result = 1;
    index = 0;
    i = strlen(str);
    while (i >= 0)
    {
        result = 1;
        if (str[i] == '1')
        {
            index = vlu;
            while (index > 1)
            {
                result *= 2;
                index--;
            }
            car += result;
        }
        vlu++;
        i--;
    }
    return ((char)car);
}

void    handler(int signal, siginfo_t *info, void *utp)
{
    (void)utp;
    static char str[8];
    static int i = 7;
    // char c;
    if (signal == SIGUSR1)
    {
        // write(1, "0", 1);
        str[i] = '0';
        i--;
    }
    if (signal == SIGUSR2)
    {
        // write(1, "1", 1);
        str[i] = '1';
        i--;
    }    
    // write(1, &str, 8);
    // write(1, "\n", 1);

    if (i == 8)
    {
    printf ("%c\n" ,convert_dec(str));
    i = 7;
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