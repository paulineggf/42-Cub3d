/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:45:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 18:41:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		fill_mapbis(char *buf, int *i, t_map *map)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (buf[k] && *i < map->y)
	{
		while (buf[k] && j < map->x)
		{
			if (buf[k] == 'N' || buf[k] == 'W'
			|| buf[k] == 'E' || buf[k] == 'S')
				init_pos(map, buf[k], j, *i);
			map->map[*i][j++] = buf[k++] - 48;
		}
		if (!buf[k])
			break ;
		else
			k++;
		j = 0;
		(*i)++;
	}
}

int				fill_map(int fd, t_map *map)
{
	int		ret;
	int		i;
	int		j;
	int		k;
	char	buf[BUFFER_CUB];

	i = 0;
	j = 0;
	while ((ret = read(fd, buf, BUFFER_CUB - 1)) > 0)
	{
		k = 0;
		buf[ret] = '\0';
		fill_mapbis(buf, &i, map);
	}
	return (ret);
}
