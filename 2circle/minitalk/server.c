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

#include "ft_minitalk.h"

t_info	g_info;

void	combine_character(char *c, char *bit_cnt)
{
	if (*c != -1)
		write(1, c, 1);
	else
	{
		g_info.pid_flag = 0;
		write(1, "\n<communication completed>\n", 28);
	}
	*c = 0;
	*bit_cnt = 0;
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	combine_char;
	static char	bit_cnt;

	(void) context;
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
		combine_character(&combine_char, &bit_cnt);
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

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)ptr;
	while (len > 0)
	{
		*temp = value;
		temp++;
		len--;
	}
	return (ptr);
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
			kill(g_info.pid, SIGUSR1);
		}
	}
	return (0);
}
