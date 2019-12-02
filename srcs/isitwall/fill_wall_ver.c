/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:22:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 21:47:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_wall_ver(t_map *map, t_pos *wall_ver)
{
	if (map->gamer->facing_right)
		wall_ver->unitx = (double)((map->gamer->posx * BLOCK_SIZE) + 64);
	else
		wall_ver->unitx = (double)((map->gamer->posx * BLOCK_SIZE) - 1);
	wall_ver->unity = (double)(map->gamer->unity + (map->gamer->unitx - wall_ver->unitx)
	* tan(map->gamer->degree * M_PI / 180.0));
	wall_ver->posx = (int)(wall_ver->unitx / (double)BLOCK_SIZE);
	wall_ver->posy = (int)(wall_ver->unity / (double)BLOCK_SIZE);
	while (wall_ver->posy >= 0 && wall_ver->posx >= 0 && wall_ver->posy < map->y
	&& wall_ver->posx < map->x && map->map[wall_ver->posy][wall_ver->posx] != 1)
	{
		if (map->gamer->facing_right)
			wall_ver->unitx = (double)(wall_ver->unitx + (double)BLOCK_SIZE);
		else
			wall_ver->unitx = (double)(wall_ver->unitx - (double)BLOCK_SIZE);
		wall_ver->unity = map->gamer->unity
		+ (map->gamer->unitx - wall_ver->unitx) * tan(map->gamer->degree * M_PI / 180.0);
		wall_ver->unity = map->gamer->unity
		+ (map->gamer->unitx - wall_ver->unitx) * tan(map->gamer->degree * M_PI / 180.0);
		wall_ver->posx = (int)(wall_ver->unitx / (double)BLOCK_SIZE);
		wall_ver->posy = (int)(wall_ver->unity / (double)BLOCK_SIZE);
	}
}
