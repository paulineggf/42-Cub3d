/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_hor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:58:24 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 15:00:40 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_wall_hor(t_map *map, t_pos *gamer, t_pos *wall_hor)
{
	if (gamer->facing_up)
		wall_hor->unity = (int)((gamer->posy * BLOCK_SIZE) - 1);
	else
		wall_hor->unity = (int)((gamer->posy * BLOCK_SIZE) + BLOCK_SIZE);
	wall_hor->unitx = (int)(gamer->unitx + (gamer->unity - wall_hor->unity) /
	tan(gamer->degree * M_PI / 180));
	wall_hor->posx = wall_hor->unitx / BLOCK_SIZE;
	wall_hor->posy = wall_hor->unity / BLOCK_SIZE;
	while (wall_hor->posy >= 0 && wall_hor->posx >= 0 && wall_hor->posy < map->y
	&& wall_hor->posx < map->x && map->map[wall_hor->posy][wall_hor->posx] == 0)
	{
		wall_hor->unitx = wall_hor->unitx
		+ (BLOCK_SIZE / tan(gamer->degree * M_PI / 180));
		if (gamer->facing_up)
			wall_hor->unity = wall_hor->unity - BLOCK_SIZE;
		else
			wall_hor->unity = wall_hor->unity + BLOCK_SIZE;
		wall_hor->posx = wall_hor->unitx / BLOCK_SIZE;
		wall_hor->posy = wall_hor->unity / BLOCK_SIZE;
	}
}
