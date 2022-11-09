/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:13:10 by jeseo             #+#    #+#             */
/*   Updated: 2022/11/08 18:16:23 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_binary(int n)
{
	if (n < 2)
		printf("%d", n % 2);
	else
	{
		print_binary(n / 2);
		print_binary(n % 2);
	}
}

int	check_line(char *map, t_flags *flags)
{
	static char	*save;
	int			i;

	i = 0;
	if (!(END_FLAG & (*flags).flag)) // 끝나지 않았을 때. 체크하고 할당.
	{
		while (map[i] != '\0' && map[i] != '\n')
		{
			if ((i == 0) || (i == (*flags).line_len - 1))
			{
				if (map[i] != '1')
					(*flags).flag |= WALL_FLAG;
			}
			if (map[i] == 'C')
			{
				(*flags).flag |= COLL_FLAG;
				(*flags).coll_cnt++;
			}
			else if (map[i] == 'E' && !(EXIT_FLAG & (*flags).flag))
				(*flags).flag |= EXIT_FLAG;
			else if (map[i] == 'P' && !(HERO_FLAG & (*flags).flag))
				(*flags).flag |= HERO_FLAG;
			else if (map[i] != '1' && map[i] != '0')
			{
				printf("WRONG COMPONENT:%c\n", map[i]);
				write(2, "FOUND WRONG COMPONENT\n", 22);
				return (ERROR);
			}
			i++;
		}
		save = strdup(map);
		if (save == NULL)
			return (ERROR);
	}
	if (((*flags).map_height == 0) || ((END_FLAG & (*flags).flag)))
	{
		i = 0;
		while (save != NULL && save[i] != '\0' && save[i] != '\n')
		{
			if (save[i] != '1')
				(*flags).flag |= WALL_FLAG;
			i++;
		}
		(*flags).line_len = i;
		if ((END_FLAG & (*flags).flag))
		{
			free(save);
			save = NULL;
		}
	}
	else if (!((*flags).map_height == 0) && (*flags).line_len != i)
	{
		printf("line: %d\ni: %d\n",(*flags).line_len, i);
		write(2, "LINE LENGTH ERROR\n", 18);
		return (ERROR);
	}
	return (1);
}

int	check_components(int flag, int len)
{
	if (WALL_FLAG & flag || !(COLL_FLAG & flag) || \
		!(EXIT_FLAG & flag) || !(HERO_FLAG & flag))
	{
		print_binary(flag);
		write(2, "COMPONENTS ERROR\n", 17);
		return (ERROR);
	}
	if (len < 3)
	{
		write(2, "LINE TOO SHORT\n", 15);
		return (ERROR);
	}
	return (0);
}

int	find_route(char *map, int collectable, char side_flag)
{
	if (collectable == -1) // escape까지 포함하기 때문에 -1.
	{
		write(1, "YOU CAN SOLVE! TRY! TRY!\n", 24);
		return (1);
	}
	/*
	다녀온 곳은 진행할 수 없도록 2로 바꾸어주면서 C와 E를 먹어본다.
	현재 위치에서 이동할 수 없는 구간, x 또는 y를 기준으로 삼아서 체크한다.
	재귀를 4번 호출하는 형식으로 하는 것이 맞을까?
	더 이상 전진할 수 없는 구간을 어떻게 판단하지?
	
	if (side_flag == DOWN)
		//맵의 인덱스 + width
	if (side_flag == RIGHT)
		//맵의 인덱스 + 1
	if (side_flag == UP)
		//맵의 인덱스 - width
	if (side_flag == LEFT)
		//맵의 인덱스 - 1
	*/
	else // 모든 곳을 다 돌았다는 플래그는 어떻게 확인할까? 더이상 진행할 수 없을 때.
	{
		find_route(map, collectable, DOWN);
		find_route(map, collectable, RIGHT);
		find_route(map, collectable, UP);
		find_route(map, collectable, LEFT);
		return (0);
	}
	return (0);
}
