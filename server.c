/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:39:31 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/09/28 17:05:47 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include <stdio.h>
void signal_handler(int sig, siginfo_t *info, void *context)
{
	static	int	i;
	int bits;
	static	char word;

	(void) (*context);
	if (sig == SIGUSR1)
		bits = 0;
	else
		bits = 1;
	word <<= 1;
	word += bits;
	i++;
	if (i == 8)
	{
		write(1, &word, 1);
		if (word == '\0')
		{
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		word = 0;
	}
}

int main()
{
	struct sigaction sa;
	pid_t pid;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}