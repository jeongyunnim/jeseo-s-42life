/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:03:54 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/08 15:02:18 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recusive_print(unsigned long long n, int flag, int *count)
{
	char	c;
	int		i;
	int		temp;

	i = 0;
	if (n < 16)
	{
		temp = *count;
		if (n < 10)
			c = n + '0';
		else if (flag == 'X')
			c = n - 10 + 'A';
		else
			c = n - 10 + 'a';
		*count += write(1, &c, 1);
		if (*count < temp)
			*count = -9999;
	}
	else
	{
		recusive_print(n / 16, flag, count);
		recusive_print(n % 16, flag, count);
	}
}

void	ft_htoa(unsigned long long n, int flag, int *count)
{
	int	temp;

	temp = *count;
	if (flag == 'p')
		*count += write(1, "0x", 2);
	else
		n = (unsigned int)n;
	if (*count < temp)
		return ;
	recusive_print(n, flag, count);
}
