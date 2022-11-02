/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:09:59 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/02 18:29:52 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>

void	esc_event(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
}

int	check_map(void)
{
	open("./map/map", );
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
