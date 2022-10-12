/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:27:20 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/12 18:51:59 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "minitalk.h"

t_info	g_info;

//void	signal_check(int signo, siginfo_t *info)
//{
//	if (g_info.pid_flag == 0)
//	{
//		g_info.pid_flag = 1;
//		if (info->si_pid != 0)
//			g_info.pid = info->si_pid;
//		printf("Who R U?: %d\n", info->si_pid);
//		info->si_status
//		g_info.grt_flag = 1;
//	}
//	else if (g_info.pid_flag == 1 && info->si_pid != g_info.pid)
//	{
//		printf("client_pid: %d, current_pid: %d\n", info->si_pid, g_info.pid);
//		printf("%d -- pid_interupt error\n", info->si_signo);
//		if (info->si_pid != 0)
//			kill(info->si_pid, SIGUSR2);
//		if (g_info.pid != 0)
//			kill(g_info.pid, SIGUSR2);
//	}
//}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	combine_char;
	static char	bit_cnt;
	static int	i;

	printf("SIGUSR1: %d, signo: %d, grt_pid: %d, sig_pid: %d\n", SIGUSR1, signo, g_info.pid, info->si_pid);
	if (signo == SIGUSR1 && g_info.grt_flag == 0)
	{
		g_info.grt_flag = 1;
		g_info.pid = info->si_pid;
		printf("communication start with %d\n", g_info.pid);
		bit_cnt--;
	}
	else if (signo == SIGUSR1)
	{
		combine_char |= (0x01 << bit_cnt);
	}
	bit_cnt++;
	if (bit_cnt == 8)
	{
		if (combine_char != -1)
		{
			write(1, &combine_char, 1);
			printf("recieved all client's massage\n");
		}
		combine_char = 0;
		bit_cnt = 0;
	}
	printf("bitcount:%d\n", bit_cnt);
	if (g_info.pid != 0 && kill(g_info.pid, SIGUSR1) == -1)
	{
		kill(g_info.pid, SIGUSR2);
	}
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
		pause();
	}
	return (0);
}
