/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:39:27 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/09/24 17:18:41 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

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
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			counter >>= 1;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	pid_t			pid;
	
	if (argc == 3)
	{
		pid = (pid_t)argv[1];
		sender(pid, argv[2]);
	}
}
