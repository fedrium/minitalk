/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:39:31 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/09/24 17:19:12 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static	int	i;
	int bits;
	static	char word;

	i = 0;
	chars = 0;
	if (sig = SIGUSR2)
		bits = 1;
	else
		bits = 0;
	c <<= 1;
	c = c + bits;
	if (i > 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction sa;
	pid_t pid;

	sa.sa_handler = &signal_handler;
	sa.sa_flag = SIG_INFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putnbr_fd((int)pid, 1);
}