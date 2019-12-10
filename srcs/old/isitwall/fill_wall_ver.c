/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:22:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/10 16:02:49 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_wall_ver(t_map *map, t_pos *wall_ver)
{
	if (map->gamer->facing_right)
		wall_ver->unitx = ((map->gamer->unitx / BLOCK_SIZE)
		* BLOCK_SIZE) + BLOCK_SIZE;
	else
		wall_ver->unitx = ((map->gamer->unitx / BLOCK_SIZE)
		* BLOCK_SIZE) - 1;
	wall_ver->unity = map->gamer->unity
	+ (map->gamer->unitx - wall_ver->unitx)
	* tan(map->gamer->degree * M_PI / 180.0);
	wall_ver->posx = wall_ver->unitx / BLOCK_SIZE;
	wall_ver->posy = wall_ver->unity / BLOCK_SIZE;
	while (wall_ver->posy >= 0 && wall_ver->posx >= 0 && wall_ver->posy < map->y
	&& wall_ver->posx < map->x && map->map[wall_ver->posy][wall_ver->posx] != 1)
	{
		if (map->gamer->facing_right)
			wall_ver->unitx += BLOCK_SIZE;
		else
			wall_ver->unitx -= BLOCK_SIZE;
		wall_ver->unity += BLOCK_SIZE * tan(map->gamer->degree * M_PI / 180.0);
		wall_ver->posx = wall_ver->unitx / BLOCK_SIZE;
		wall_ver->posy = wall_ver->unity / BLOCK_SIZE;
	}
}
