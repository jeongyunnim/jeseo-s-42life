/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/04 17:29:27 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esc_event(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}

int	check_map(void *mlx_ptr, void *win_ptr, int fd)
{
	t_flags	flags;
	char	*map_line;
	char	*map;

	memset(flags, 0, sizeof(flags));
	map_line = NULL;
	while (!(flags.flag & END_FLAG))
	{
		map_line = get_next_line(fd);
		if (map_line && *map_line)
		{
			if (check_line(map_line, &flags) == ERROR);
				return (ERROR);
			if (check_components(&flags) == ERROR);
				return (ERROR);
		}
		else
		{
			flags.flag |= END_FLAG;
			if (check_line(map_line, &flags) == ERROR);
				return (ERROR);
		}
		map = strnjoin(map, map_line, flags.line_len - 1);
		if (map == NULL)
			return (ERROR);
	}
	return (0);
}
//length가 1인 사각형은 제외 length가 2인 사각형은 고민

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;

	fd = open("./map/map", O_RDONLY);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");// how to estimate window's length? '1' length?
	mlx_loop(mlx_ptr);
	check_map(mlx_ptr, win_ptr. fd);
	return (0);
}
