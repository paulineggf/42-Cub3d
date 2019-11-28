/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:57:35 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/26 18:28:13 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	define_ybis(int fd, char *buf, int *i, t_map *map)
{
	int		ret;

	while ((ret = read(fd, buf, BUFFER_CUB - 1)) > 0)
	{
		buf[ret] = '\0';
		while (buf[*i])
		{
			while (buf[*i] && buf[*i] != '\n')
			{
				if (*i + map->x < ret)
					*i = *i + map->x + 1;
				else
					(*i)++;
			}
			if (buf[*i] == '\n')
			{
				map->y++;
				if (*i + map->x < ret)
					*i = *i + map->x + 1;
				else
					(*i)++;
			}
		}
	}
	return (ret);
}

int			define_y(int fd, char *buf, t_map *map, int *ret)
{
	int		i;

	i = map->x;
	map->y = 1;
	while (buf[i])
	{
		while (buf[i] && buf[i] != '\n')
		{
			if (i + map->x < *ret)
				i += i + map->x + 1;
			else
				i++;
		}
		if (buf[i] == '\n')
		{
			map->y++;
			if (i + map->x < *ret)
				i = i + map->x + 1;
			else
				i++;
		}
	}
	return (define_ybis(fd, buf, &i, map));
}
