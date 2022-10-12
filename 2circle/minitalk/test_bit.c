/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:20:53 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/03 13:04:22 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	make_binary(int i)
{
	char	binary_arr[] = "01";

	if(i < 2)
	{
		if (i % 2 == 0)
			write(1, &binary_arr[0], 1);
		else
			write(1, &binary_arr[1], 1);
	}
	else
	{
		make_binary(i/2);
		make_binary(i%2);
	}
}

int	main(void)
{
	int		i;
	char	c;

	i = 'A';
	printf("i: %c\n", i);
	make_binary(i);
	write(1, "\n", 1);
	i |= (1 << 5);
	printf("i: %c\n", i);
	make_binary(i);
	write(1, "\n", 1);
	return (0);
}
