/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_ver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:22:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/29 20:14:22 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	printf("unity : %d\n", wall_ver->unity);
	printf("unitx : %d\n", wall_ver->unitx);
	printf("posy : %d\n", wall_ver->posy);
	printf("posx : %d\n", wall_ver->posx);
	printf("map : %d\n", map->map[wall_ver->posy][wall_ver->posx]);*/

void	fill_wall_ver(t_map *map, t_pos *gamer, t_pos *wall_ver)
{
	if (gamer->facing_right)
		wall_ver->unitx = (int)((gamer->posx * BLOCK_SIZE) + 64);
	else
		wall_ver->unitx = (int)((gamer->posx * BLOCK_SIZE) - 1);
	wall_ver->unity = (int)(gamer->unity + (gamer->unitx - wall_ver->unitx)
	* tan(gamer->degree * M_PI / 180));
	wall_ver->posx = wall_ver->unitx / BLOCK_SIZE;
	wall_ver->posy = wall_ver->unity / BLOCK_SIZE;
	while (wall_ver->posy >= 0 && wall_ver->posx >= 0 && wall_ver->posy < map->y
	&& wall_ver->posx < map->x && map->map[wall_ver->posy][wall_ver->posx] == 0)
	{
		if (gamer->facing_right && ((wall_ver->unitx + BLOCK_SIZE) / BLOCK_SIZE) < map->x)
			break ;
		if (gamer->facing_left && ((wall_ver->unitx + BLOCK_SIZE) / BLOCK_SIZE) < map->x)
			break ;
		int tmpx;
		int	tmpy;
		if (gamer->facing_right)
			tmpx = wall_ver->unitx + BLOCK_SIZE;
		else if (gamer->facing_right)
			tmpx = wall_ver->unitx - BLOCK_SIZE;
		if (tmpx > map->x)
			break ;
		tmpy = gamer->unity
		+ (gamer->unitx - tmpx) * tan(gamer->degree * M_PI / 180);
		if (tmpy > map->y)
			break ;
		wall_ver->posx = wall_ver->unitx / BLOCK_SIZE;
		wall_ver->posy = wall_ver->unity / BLOCK_SIZE;
	}
}
