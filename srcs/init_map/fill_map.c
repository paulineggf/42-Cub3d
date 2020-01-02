/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:18:18 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 19:26:24 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(char *tmp, int i, t_map *map)
{
	int		y;
	int		x;

	y = -1;
	while (y++ < map->y - 1)
	{
		x = -1;
		while (x++ < map->x - 1)
		{
			if (tmp[i] == ' ')
				i++;
			if (tmp[i] == '2')
				map->size_sprite++;
			if (tmp[i] == 'N' || tmp[i] == 'W'
			|| tmp[i] == 'E' || tmp[i] == 'S')
			{
				init_pos(map, tmp[i], x, y);
				map->map[y][x] = 0;
			}
			else
				map->map[y][x] = tmp[i] - 48;
			i++;
		}
	}
	free(tmp);
}
