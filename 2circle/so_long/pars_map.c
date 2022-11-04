/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:13:10 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/04 17:56:49 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *map, t_flags *flags)
{
	int	i;

	i = 0;
	if (((*flags).map_size == 0) && ((*flags).flag & END_FLAG))
	{
		while (map[i] != '\0')
		{
			if (map[i] != 1)
				(*flags).flag |= WALL_FLAG;
		}
		(*flags).line_len = i;
	}
	else
	{
		while (map[i] != '\0')
		{
			if ((i == 0) && (i = (*flags).line_len - 1))
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
			else 
			{
				wirte(2, "COMPONENTS ERROR\n", 17);
				return (ERROR);
			}
		}
	}
	if ((*flags).line_len != i)
	{
		write(2, "LINE LENGTH ERROR\n", 22);
		return (ERROR);
	}
	return (1);
}

int	check_components(int flag)
{
	if (WALL_FLAG & flag || !(COLL_FLAG & flag) || \
		!(EXIT_FLAG & flag) || (HERO_FLAG & flag))
	{
		write(2, "COMPONENTS ERROR\n", 17);
		return (-1);
	}
}