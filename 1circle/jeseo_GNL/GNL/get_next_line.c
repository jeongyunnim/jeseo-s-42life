/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:18:09 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/01 19:57:23 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
// #define BUFFER_SIZE 10

static void	save_buff(char **save, char *buff, size_t i)
{
	if (i == BUFFER_SIZE)
		(*save)[0] = '\0';
	else
		ft_strlcpy(*save, buff, BUFFER_SIZE - i + 1);
}

static char	*ret_line(char *dest, char *src, char *save, int *flag)
{
	size_t	len;
	char	*temp;
	char	*line;

	len = 0;
	temp = 0;
	while (src[len] != '\n' && src[len] != '\0')
		len++;
	if (src[len] == '\n')
	{
		len++;
		*flag = 1;
	}
	else if (src[len] == '\0' && len < BUFFER_SIZE && !(*save != 0))
		*flag = 1;
	line = ft_strnjoin(&dest, src, len);
	save_buff(&save, src + len, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			flag;

	line = 0;
	flag = 0;
	while (1)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if (*save != 0)
			line = ret_line(line, save, save, &flag);
		else if (read(fd, buff, BUFFER_SIZE) <= 0)
			return (line);
		else
			line = ret_line(line, buff, save, &flag);
		if (flag == 1)
			return (line);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 1;
// 	fd = open("./test.txt", O_RDONLY);
// 	if (fd > 0)
// 	{
// 		while (line != 0)
// 		{
// 			line = get_next_line(fd);
// 			printf("\n%d번째 줄: %s", i++, line);
// 			free(line);
// 		}
// 	}
// 	else
// 		return (printf("failed open file\n"));
// 	close(fd);
// 	return (0);
// }
