/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/12 16:20:39 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	esc_event(void *mlx_ptr, void *win_ptr)
// {
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// }

int	check_map(int fd)
{
	t_flags	flags;
	char	*map_line;
	char	*map;
	int 	i;

	memset(&flags, 0, sizeof(flags));
	map_line = NULL;
	map = (char *)calloc(sizeof(char), 1);
	while (!(END_FLAG & flags.flag))
	{
		map_line = get_next_line(fd);
		if (map_line && *map_line)
		{
			if (check_line(map_line, &flags) == ERROR)
				return (ERROR);
			map = ft_strnjoin(&map, map_line, flags.line_len);
			if (map == NULL)
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
		free(map_line);
		map_line = NULL;
		flags.map_height++;
	}
	i = 0;
	printf("line_line: %d\n", flags.line_len);
	while (map[i])
	{
		printf("%c", map[i]);
		if (i % flags.line_len == flags.line_len - 1)
			printf("\n");
		i++;
	}
	find_route(map, flags.p, &flags.coll_cnt, flags.line_len);
	if (flags.coll_cnt != 0)
	{
		write(1, "IT CAN'T BE SOLVED\n", 19);
		return (ERROR);
	}
	else
	{
		write(1, "YOU CAN SOLVE! TRY! TRY!\n", 24);
		if (open_and_draw(map, flags) == ERROR)
			return (ERROR);
	}
	return (0);
}

void	initialize_map(void *mlx_ptr, void* win_ptr, t_flags flag)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = -1;
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./source/tile.xpm", &width, &height);
	while (++i < flag.map_height)
	{
		j = -1;
		while (++j < flag.line_len)
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, width * j, height * i);
	}
}

int	open_and_draw(char *map, t_flags flag)
{
	t_image	wall;
	t_image	coll;
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	i = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, flag.line_len * 32, (flag.map_height - 1) * 32, "test");
	initialize_map(mlx_ptr, win_ptr, flag);
	wall.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./source/wall.xpm", &wall.width, &wall.height);
	coll.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./source/coll.xpm", &coll.width, &coll.height);
	printf("%s\n", map);
	while (map[++i] != '\0')
	{
		if (map[i] == '1')
			mlx_put_image_to_window(mlx_ptr, win_ptr, wall.img_ptr, (i % flag.line_len) * 32, (i / flag.line_len) * 32);
		else if (map[i] == 'C')
			mlx_put_image_to_window(mlx_ptr, win_ptr, coll.img_ptr, (i % flag.line_len) * 32, (i / flag.line_len) * 32);
		//printf("x: %d, y: %d\n", (i % flag.line_len) * 32, (i / flag.line_len) * 32);
		//mlx_string_put(mlx_ptr, win_ptr, (i % flag.line_len) * 32, (i / flag.line_len) * 32, 0x48385E, "WALL");
	}
	mlx_loop(mlx_ptr);
	// how to estimate window's length? '1' length?
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (write(2, "ERROR\n", 6));
	//if (argv[1] != "*.ber")
	//	return (write(2, "ERROR\n", 6));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (check_map(fd) == ERROR)
	{
		close(fd);
		return (write(2, "ERORR\nIT CAN'T BE SOLVED\n", 25));//perror?
	}
	close(fd); //close 왜 해줘??
	return (0);
}
