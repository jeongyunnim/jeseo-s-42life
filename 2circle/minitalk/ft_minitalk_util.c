/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_util_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:50:27 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/19 19:03:14 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
	c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
	{
		num = num * 10 + str[i++] - '0';
		if (sign == 1 && num > 2147483647)
			return (-1);
		else if (sign == -1 && num > 2147483648)
			return (0);
	}
	return (num * sign);
}

void	*ft_memset(void *bytes, int value, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)bytes;
	while (len > 0)
	{
		*temp = value;
		temp++;
		len--;
	}
	return (bytes);
}

void	print_pid(pid_t pid)
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
