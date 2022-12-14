/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:29:34 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/19 18:58:29 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_info	g_info;

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		g_info.grt_flag = 1;
	else if (signo == SIGUSR2)
	{
		write(2, "<COMMUNICATION ERROR>\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	send_character(int pid, unsigned char c)
{
	int			i;
	int			kill_flag;

	i = 8;
	kill_flag = 0;
	while (i != 0)
	{
		if (g_info.grt_flag == 1)
		{
			g_info.grt_flag = 0;
			if (c % 2 == 1)
				kill_flag = kill(pid, SIGUSR1);
			else
				kill_flag = kill(pid, SIGUSR2);
			c /= 2;
			i--;
		}
		if (kill_flag == ERROR)
			exit(EXIT_FAILURE);
	}
}

int	find_server(pid_t server_pid)
{
	if (kill(server_pid, SIGUSR1) == ERROR)
		exit(EXIT_FAILURE);
	while (1)
	{
		if (g_info.grt_flag == 1)
			break ;
	}
	return (0);
}

void	initialize_sigaction(void)
{
	struct sigaction	sigact;

	ft_memset(&sigact, 0, sizeof(sigact));
	sigact.__sigaction_u.__sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
}

int	main(int argc, char **argv)
{
	int					server_pid;

	if (argc != 3)
	{
		write(2, "<ARGUMENT COUNT ERROR>\n", 23);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || 100000 <= server_pid)
	{
		write(2, "<PID ERROR>\n", 12);
		exit(EXIT_FAILURE);
	}
	initialize_sigaction();
	find_server(server_pid);
	while (*argv[2])
	{
		send_character(server_pid, *argv[2]);
		argv[2]++;
	}
	send_character(server_pid, 0);
	write(1, "<server received all>\n", 22);
	return (0);
}
