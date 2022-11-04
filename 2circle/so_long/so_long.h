/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:48:24 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/02 21:53:47 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

# define WALL_FLAG	0x01 // 0000 0001
# define HERO_FLAG	0x02 // 0000 0010
# define COLL_FLAG	0x04 // 0000 0100
# define ESCP_FLAG	0x08 // 0000 1000
# define END_FLAG	0x10 // 0001 0000
# define ENE_FLAG	0x20 // 0010 0000

void	*ft_memset(void *bytes, int value, size_t len);

char	*ft_strnjoin(char **s1, char const *s2, size_t len);
char	*ft_strndup(const char *str, int str_len);
char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

typedef struct s_flagss
{
	int		map_size;
	int		line_len;
	char	flag;
}				t_flags;
#endif