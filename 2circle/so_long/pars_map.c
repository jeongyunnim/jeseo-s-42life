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
	if (((*flags).map_size == 1) || ((END_FLAG & (*flags).flag)))
	{
		while (map != NULL && map[i] != '\0' && map[i] != '\n')
		{
			if (map[i] != 1)
				(*flags).flag |= WALL_FLAG; write(1, "wall on1\n", 9);
			i++;
		}
		(*flags).line_len = i;
		free(save);
		save = NULL;
	}
	else
	{
		while (map[i] != '\0')
		{
			if ((i == 0) && (i == (*flags).line_len - 2))
			{
				if (map[i] != 1)
					(*flags).flag |= WALL_FLAG; write(1, "wall on2\n", 9);
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
	}
	if (!((*flags).map_size == 0) && (*flags).line_len != i)
	{
		printf("a: %d\nb: %d\n",(*flags).line_len, i);
		write(2, "LINE LENGTH ERROR\n", 18);
		return (ERROR);
	}
	return (1);
}

int	check_components(int flag, int len)
{
	if (WALL_FLAG & flag || !(COLL_FLAG & flag) || \
		!(EXIT_FLAG & flag) || (HERO_FLAG & flag))
	{
		printf("%d\n", flag);
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