/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:49:09 by jeseo             #+#    #+#             */
/*   Updated: 2022/07/29 13:21:25 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *bytes, int value, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)bytes;
	while (len > 0)
	{
		*temp = value;
		temp++;
		len--;
	}
	return (bytes);
}

// void	ft_lstadd_back(t_text **lst)
// {
// 	t_text	*new;
// 	t_text	*temp;

// 	new = (t_text *)malloc(1 * sizeof(t_text));
// 	if (!lst || !new)
// 		return ;
// 	else if (!*lst)
// 		*lst = new;
// 	else
// 	{
// 		temp = *lst;
// 		while (temp -> next)
// 			temp = temp -> next;
// 		temp -> next = new;
// 	}
// }

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	i = 0;
	while (i + 1 < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size > 0)
		dest[i] = '\0';
	return (0);
}

char	*ft_strndup(const char *str, int str_len)
{
	int		i;
	char	*str_dup;

	i = 0;
	str_dup = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str_dup == NULL)
		return (NULL);
	while (i < str_len)
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

char	*ft_strnjoin(char **s1, char const *s2, size_t len)
{
	size_t	s1_len;
	char	*res;

	s1_len = 0;
	while (*s1 && (*s1)[s1_len])
		s1_len++;
	res = (char *)malloc((s1_len + len + 1) * sizeof(char));
	if (res == 0)
	{
		if (*s1)
			free(*s1);
		return (NULL);
	}
	if (*s1)
	{
		ft_strlcpy(res, *s1, s1_len + 1);
		free(*s1);
	}
	ft_strlcpy(res + s1_len, s2, len + 1);
	return (res);
}
