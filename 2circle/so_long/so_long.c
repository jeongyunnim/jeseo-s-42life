/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/04 20:31:50 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	esc_event(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}

int	check_map(int fd)
{
	t_flags	flags;
	char	*map_line;
	char	*map;

	memset(&flags, 0, sizeof(flags));
	map_line = NULL;
	map = (char *)calloc(sizeof(char), 1);
	while (!(END_FLAG & flags.flag))
	{
		map_line = get_next_line(fd);
		printf("%s", map_line);
		if (map_line && *map_line)
		{
			if (check_line(map_line, &flags) == ERROR)
				return (ERROR);
		}
		else
		{
			flags.flag |= END_FLAG;
			if (check_line(map_line, &flags) == ERROR)
				return (ERROR);
			if (check_components(flags.flag, flags.line_len) == ERROR)
				return (ERROR);
		}
		map = ft_strnjoin(&map, map_line, flags.line_len - 1);
		if (map == NULL)
			return (ERROR);
		free(map_line);
		map_line = NULL;
		flags.map_size++;
	}
	return (0);
}
//length가 1인 사각형은 제외 length가 2인 사각형은 고민

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;

	fd = open("./map/map.txt", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");// how to estimate window's length? '1' length?
	//mlx_loop(mlx_ptr);
	check_map(fd);
	close(fd); //close 왜 해줘??
	return (0);
}
