/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:51 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/08 14:57:05 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptoa(void *ptr, int flag, int *count)
{
	unsigned long long	casting_ptr;

	casting_ptr = (unsigned long long)ptr;
	return (ft_htoa(casting_ptr, flag, count));
}

static int	converse_char(va_list ap, int c, int *count)
{
	char	print_char;
	int		temp;

	temp = *count;
	if (c == 'c')
	{
		print_char = va_arg(ap, int);
		*count += write(1, &print_char, 1);
		if (*count < temp)
			return (-1);
		return (0);
	}
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_itoa(va_arg(ap, int), count, c);
	else if (c == 'x' || c == 'X')
		ft_htoa(va_arg(ap, int), c, count);
	else if (c == 'p')
		ft_ptoa(va_arg(ap, void *), c, count);
	else
		return (-1);
	if (*count < temp)
		return (-1);
	return (0);
}

int	ft_printf(const char *ar, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	count = 0;
	va_start(ap, ar);
	while (*ar)
	{
		temp = count;
		if (*ar != '%')
			count += write(1, ar, 1);
		else if (*(++ar) != '%')
		{
			if (converse_char(ap, *ar, &count) != 0)
				return (-1);
		}
		else if (*ar == '%')
			count += write(1, "%", 1);
		if (count < temp)
			return (-1);
		ar++;
	}
	va_end(ap);
	return (count);
}
