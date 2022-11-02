/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:48:24 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/02 21:18:10 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

void	*ft_memset(void *bytes, int value, size_t len);

char	*ft_strnjoin(char **s1, char const *s2, size_t len);
char	*ft_strndup(const char *str, int str_len);
char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

typedef struct s_flags
{
	int		map_size;
	char	wall_flag;
	char	hero_flag;
	char	coll_flag;
}				t_flags;

#endif