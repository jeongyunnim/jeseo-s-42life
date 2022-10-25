/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:19:35 by jeseo             #+#    #+#             */
/*   Updated: 2022/07/29 13:21:26 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

// struct s_text
// {
// 	int				fd;
// 	struct s_text	*back_up;
// 	struct s_text	*next;
// }					t_text;

void	*ft_memset(void *bytes, int value, size_t len);

char	*ft_strnjoin(char **s1, char const *s2, size_t len);
char	*ft_strndup(const char *str, int str_len);
char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

// t_text	*ft_lstnew(void *content);

#endif