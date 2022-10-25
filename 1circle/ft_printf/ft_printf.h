/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:53 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/08 15:22:08 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_itoa(long long n, int *count, int flag);
void	ft_htoa(unsigned long long n, int flag, int *count);
void	ft_putstr(char *s, int *count);

int		ft_printf(const char *ar, ...);

size_t	ft_strlen(const char *str);

#endif
