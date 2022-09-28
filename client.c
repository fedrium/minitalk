/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:39:27 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/09/28 17:15:01 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include <stdio.h>
void sender(pid_t pid, char *msg)
{
	int i;
	int counter;

	i = 0;
	while (msg[i] != '\0')
	{
		counter = 128;
		while (counter > 0)
		{
			if (msg[i] / counter == 0)
			{
				kill(pid, SIGUSR1);
				// printf("sending siguser1 to %d\n", pid);
			}	
			else
			{
				kill(pid, SIGUSR2);
				// printf("sending siguser2 to %d\n", pid);
			}
			msg[i] = msg[i] % counter;
			counter >>= 1;
			usleep(100);
		}
		i++;
	}
}

void confirm()
{
	write(1, "Message Received\n", 20);
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	pid_t			pid;
	char 			*msg;
	
	if (argc == 3)
	{
		sa.sa_handler = &confirm;
		sigaction(SIGUSR1, &sa, NULL);
		pid = (pid_t)ft_atoi(argv[1]);
		msg = argv[2];
		sender(pid, msg);
	}
}
