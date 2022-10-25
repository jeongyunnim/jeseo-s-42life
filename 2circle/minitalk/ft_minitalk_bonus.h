/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:33:13 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/19 19:03:22 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR -1

void	*ft_memset(void *bytes, int value, size_t len);
int		ft_atoi(const char *str);
void	print_pid(pid_t pid);

typedef struct s_info
{
	pid_t	pid;
	int		pid_flag;
	int		grt_flag;
}				t_info;

#endif