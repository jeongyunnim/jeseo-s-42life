/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:27:20 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/13 20:45:27 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "minitalk.h"

t_info	g_info;

//void	combine_character(char *c, char *bit_cnt)
//{
//	if (*c != -1)
//		write(1, c, 1);
//	else
//	{
//		g_info.pid_flag = 0;
//		write(1, "\n<communicatioin completed>\n", 28);
//	}
//	*c = 0;
//	bit_cnt = 0;
//}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	combine_char;
	static char	bit_cnt;

	if (info->si_pid == 0)
		return ;
	g_info.pid = info->si_pid;
	if (g_info.pid_flag == 0)
	{
		g_info.pid_flag = 1;
		kill(g_info.pid, SIGUSR1);
		return ;
	}
	if (signo == SIGUSR1)
		combine_char |= (0x01 << bit_cnt);
	bit_cnt++;
	if (bit_cnt == 8)
	{
		if (combine_char != -1)
			write(1, &combine_char, 1);
		else
		{
			g_info.pid_flag = 0;
			write(1, "\n<communicatioin completed>\n", 28);
		}
		combine_char = 0;
		bit_cnt = 0;
	}
	g_info.grt_flag = 1;
}

void	print_pid(int pid)
{
	char	char_num;

	if (pid < 10)
	{
		char_num = pid + '0';
		write(1, &char_num, 1);
	}
	else
	{
		print_pid(pid / 10);
		print_pid(pid % 10);
	}
}

int	main(void)
{
	struct sigaction	sigact;
	pid_t				server_pid;

	server_pid = getpid();
	memset(&sigact, 0, sizeof(sigact));
	memset(&g_info, 0, sizeof(g_info));
	sigact.sa_flags |= SA_SIGINFO;
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
			kill(g_info.pid, SIGUSR1);
		}
	}
	return (0);
}
