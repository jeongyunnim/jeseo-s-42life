/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/11 21:06:33 by jeseo            ###   ########.fr       */
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
	int i = 0;

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
		write(1, "IT CAN'T BE SOLVED\n", 19);
	else
		write(1, "YOU CAN SOLVE! TRY! TRY!\n", 24);
	return (0);
}

int	open_and_draw(void *mlx_ptr)
{
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
	int 	i;

	i = 0;	
	//width = 1000;
	//height = 1000;
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./source/tile.xpm", &width, &height);
	win_ptr = mlx_new_window(mlx_ptr, width * 10, height * 10, "test");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, width * i, 0 + i);
	// how to estimate window's length? '1' length?
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
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
	mlx_ptr = mlx_init();
	open_and_draw(mlx_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
