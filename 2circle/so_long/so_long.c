/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/02 21:55:44 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esc_event(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}

int	check_map(void *mlx_ptr, void *win_ptr)
{
	t_flags	flags;
	char	*map;

	memset(flags, 0, sizeof(flags));
	map = NULL;
	while (1)
	{
		map = get_next_line(fd);
		if (map)
		{
			if ((flags.map_size == 0) && (flags.flag & END_FLAG))
			{
				//check all components are wall(1)
			}
			else
			{
				//check side components are wall(1)
				//check hero, collectable things, escape, and enemy
				//check line length
			}
		}
		else
		// length가 1인 사각형은 제외 length가 2인 사각형은 고민
		//free 하기 전에 map line이 null이면 
		{
			close(fd);
			return (-1);
		}
		map++;
		close(fd);
	}
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;

	fd = open("./map/map", O_RDONLY);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test"); // how to estimate window's length? '1' length?
	mlx_loop(mlx_ptr);
	check_map(mlx_ptr, win_ptr);
	return (0);
}
