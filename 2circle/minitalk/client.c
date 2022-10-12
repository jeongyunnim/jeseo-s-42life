/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:29:34 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/12 18:12:15 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "minitalk.h"

t_info	g_info;

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		printf("OK\n");
		g_info.grt_flag = 1;
	}
	else if (signo == SIGUSR2)
	{
		write(1, "wrong packet\n", 13);
		exit(1);
	}
}

void	send_character(int pid, char c)
{
	int	i;

	i = 8;
	printf("c: %c\n", c);
	while (i-- != 0 && g_info.grt_flag == 1)
	{
		if (c % 2 == 1)
		{
			kill(pid, SIGUSR1);
			printf("send 1");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("send 2");
		}
		c /= 2;
		g_info.pid_flag = 0;
		pause();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	int					server_pid;

	server_pid = atoi(argv[1]);
	memset(&sigact, 0, sizeof(sigact));
	g_info.grt_flag = 1;
	sigact.__sigaction_u.__sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	if (argc != 3)
	{
		return (-1);
	}
	else
	{
		while (*argv[2])
		{
			send_character(server_pid, *argv[2]);
			argv[2]++;
		}
	}
	send_character(server_pid, -1);
	write(1, "server recieved all\n", 20);
	return (0);
}
