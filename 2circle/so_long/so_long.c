/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/02 21:41:12 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esc_event(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}

int	draw_map(void)
{
	t_flags	flags;
	int		fd;
	char	*map;

	fd = open("./map/map", O_RDONLY);
	memset(flags, 0, sizeof(flags));
	map = NULL;
	if (fd > 0)
	{
		while (1)
		{
			map = get_next_line(fd);
			if (map)
			{
				if (flags.map_size)
					
			}
			// 모서리가 모두 벽인지.
			// 1인 사각형은 제외 2인 사각형은..?
			// 요소가 적절하게 다 들어있는지
			// 그리기도 바로 여기서??
			map++;
		}
		//free 하기 전에 map line이 null이면 
	}
	else
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 1000, 1000, "test");
	mlx_loop(mlx_ptr);
	check_map(mlx_ptr, win_ptr);
	return (0);
}
