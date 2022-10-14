/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:29:34 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/13 20:45:27 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minitalk.h"

t_info	g_info;

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
		g_info.grt_flag = 1;
	else if (signo == SIGUSR2)
	{
		write(1, "wrong packet\n", 13);
		exit(1);
	}
}

void	send_character(int pid, unsigned char c)
{
	int	i;

	i = 8;
	write(1, "-----------------\n", 18);
	while (i != 0)
	{
		if (g_info.grt_flag == 1)
		{
			g_info.grt_flag = 0;
			if (c % 2 == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c /= 2;
			i--;
		}
	}
}

int	find_server(pid_t server_pid)
{
	if (kill(server_pid, SIGUSR1) == -1)
		exit(1);
	while (1)
	{
		if (g_info.grt_flag == 1)
			break ;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact;
	int					server_pid;

	server_pid = atoi(argv[1]);
	memset(&sigact, 0, sizeof(sigact));
	g_info.grt_flag = 0;
	sigact.__sigaction_u.__sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	find_server(server_pid);
	if (argc != 3)
		return (-1);
	while (*argv[2])
	{
		send_character(server_pid, *argv[2]);
		argv[2]++;
	}
	send_character(server_pid, -1);
	write(1, "server recieved all\n", 20);
	return (0);
}
