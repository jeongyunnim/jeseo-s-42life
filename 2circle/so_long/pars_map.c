/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:13:10 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/04 21:28:26 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *map, t_flags *flags)
{
	static char	*save;
	int			i;

	i = 0;
	if (!(END_FLAG & (*flags).flag))
	{
		while (map[i] != '\0')
		{
			printf("%c", map[i]);
			if ((i == 0) && (i == (*flags).line_len - 2))
			{
				if (map[i] != 1)
					(*flags).flag |= WALL_FLAG;
			}
			if (map[i] == 'C')
				(*flags).flag |= COLL_FLAG;
			else if (map[i] == 'E')
				(*flags).flag |= EXIT_FLAG;
			else if (map[i] == 'P')
				(*flags).flag |= HERO_FLAG;
			i++;
		}
		save = strdup(map);
		if (save == NULL)
			return (ERROR);
	}
	if (((*flags).map_size == 1) || ((END_FLAG & (*flags).flag)))
	{
		while (save != NULL && save[i] != '\0' && save[i] != '\n')
		{
			if (save[i] != '1')
				(*flags).flag |= WALL_FLAG;
			i++;
		}
		(*flags).line_len = i;
		if ((END_FLAG & (*flags).flag))
		{
			free(save);
			save = NULL;
		}
	}
	if (!((*flags).map_size == 0) && (*flags).line_len != i)
	{
		printf("line: %d\ni: %d\n",(*flags).line_len, i);
		write(2, "LINE LENGTH ERROR\n", 18);
		return (ERROR);
	}
	return (1);
}

void	print_binary(int n)
{
	if (n < 2)
		printf("%d", n % 2);
	else
	{
		print_binary(n / 2);
		print_binary(n % 2);
	}
}

int	check_components(int flag, int len)
{
	if (WALL_FLAG & flag || !(COLL_FLAG & flag) || \
		!(EXIT_FLAG & flag) || !(HERO_FLAG & flag))
	{
		print_binary(flag);
		write(2, "COMPONENTS ERROR\n", 17);
		return (-1);
	}
	if (len < 3)
	{
		write(2, "TOO SHORT LINE LENGTH\n", 22);
		return (-1);
	}
	return (0);
}