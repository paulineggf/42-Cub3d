/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:22:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/05 18:32:25 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_wall_ver(t_map *map, t_pos *wall_ver)
{
	if (map->gamer->beta == 30)
	{
		printf("map->gamer->posx : %d\nmap->gamer->posy : %d\n", map->gamer->posx, map->gamer->posy);
		printf("map->gamer->unitx : %d\nmap->gamer->unity : %d\n\n", map->gamer->unitx, map->gamer->unity);
	}
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
	if (map->gamer->beta == 30)
		printf("wall_ver->unitx : %d\nwall_ver->unity : %d\nwall_ver->posx : %d\nwall_ver->posy : %d\n\n", wall_ver->unitx, wall_ver->unity, wall_ver->posx, wall_ver->posy);	
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
	if (map->gamer->beta == 30)
		printf("wall_ver->unitx : %d\nwall_ver->unity : %d\nwall_ver->posx : %d\nwall_ver->posy : %d\n\n", wall_ver->unitx, wall_ver->unity, wall_ver->posx, wall_ver->posy);	

}
