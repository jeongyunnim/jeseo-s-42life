/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:27:20 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/19 19:08:13 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_info	g_info;

void	kill_error(void)
{
	write(2, "\n<ERROR OCCURED>\n", 17);
	kill(g_info.pid, SIGUSR2);
	ft_memset(&g_info, 0, sizeof(g_info.pid));
	kill(getpid(), SIGUSR2);
}

void	combine_character(char *c, char *bit_cnt)
{
	if (*c != 0)
		write(1, c, 1);
	else
		g_info.pid_flag = 0;
	*c = 0;
	*bit_cnt = 0;
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	combine_char;
	static char	bit_cnt;

	(void)context;
	if (info->si_pid == 0)
		return ;
	else if (info->si_pid == getpid())
		return (combine_character(&combine_char, &bit_cnt));
	else if (g_info.pid_flag == 1 && info->si_pid != g_info.pid)
	{
		kill(info->si_pid, SIGUSR2);
		return (kill_error());
	}
	g_info.pid = info->si_pid;
	if (g_info.pid_flag == 0)
	{
		g_info.pid_flag = 1;
		kill(g_info.pid, SIGUSR1);
		return ;
	}
	if (signo == SIGUSR1)
		combine_char |= (0x01 << bit_cnt);
	if (++bit_cnt == 8)
		combine_character(&combine_char, &bit_cnt);
	g_info.grt_flag = 1;
}

int	main(void)
{
	struct sigaction	sigact;
	pid_t				server_pid;

	server_pid = getpid();
	ft_memset(&sigact, 0, sizeof(sigact));
	sigact.__sigaction_u.__sa_sigaction = signal_handler;
	write(1, "pid: ", 6);
	print_pid(server_pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
	{
		if (g_info.grt_flag == 1)
		{
			g_info.grt_flag = 0;
			if (kill(g_info.pid, SIGUSR1) == ERROR)
				kill_error();
		}
	}
	return (0);
}
