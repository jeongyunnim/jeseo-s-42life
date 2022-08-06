/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:03:54 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/06 16:02:23 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_hex(char **ret, long long hex, size_t len)
{
	(*ret)[0] = '0';
	(*ret)[1] = 'x';
	(*ret)[len + 1] = '\0';
	while (len > 0)
	{
		if ((hex % 16) < 10)
			(*ret)[len + 1] = (hex % 16) + '0';
		else
			(*ret)[len + 1] = (hex % 16) - 10 + 'a';
		hex /= 16;
		len--;
	}
	return ;
}

char	*ft_htoa(long long hex, char flag)
{
	size_t		len;
	long long	temp;
	char		*ret;

	temp = hex;
	len = 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * len + 3);
	if (ret == NULL)
		return (NULL);
	fill_hex(&ret, hex, len);
	if (flag == 'X')
		ft_strupper(&ret);
	return (ret);
}
