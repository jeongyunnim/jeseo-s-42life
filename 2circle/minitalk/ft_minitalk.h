/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:33:13 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/18 16:55:56 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR -1

void	*ft_memset(void *bytes, int value, size_t len);
int		ft_atoi(const char *str);

typedef struct s_info
{
	pid_t	pid;
	int		pid_flag;
	int		grt_flag;
}				t_info;

#endif