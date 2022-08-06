/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:53 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/06 16:04:20 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> // have to remove.
# include <string.h> // have to remove.
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
char	*ft_htoa(long long hex, char flag);
char	*ft_strdup(const char *str);

size_t	ft_strlen(const char *str);

void	ft_strupper(char **ret);

#endif
