/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:36:13 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/04 20:21:46 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*positive(int n)
{
	int		count;
	int		temp;
	char	*ret;

	count = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	if (n == 0)
		count++;
	ret = (char *)malloc((count + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[count] = '\0';
	while (count > 0)
	{
		ret[count - 1] = n % 10 + '0';
		n /= 10;
		count--;
	}
	return (ret);
}

static char	*negetive(int n)
{
	int			count;
	long long	n_long;
	char		*ret;

	count = 0;
	n_long = (long long)n * -1;
	while (n_long > 0)
	{
		n_long /= 10;
		count++;
	}
	ret = (char *)malloc((count + 2) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	n_long = (long long)n * -1;
	ret[count + 1] = '\0';
	while (count > 0)
	{
		ret[count] = n_long % 10 + '0';
		n_long /= 10;
		count--;
	}
	ret[0] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (positive(n));
	else
		return (negetive(n));
}
