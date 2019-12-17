/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:03:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 20:36:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_map *map)
{
	map->i = 0;
	while (map->i <= map->size_sprite)
	{
		printf("map->sprite[%d]->mapx : %d && map->sprite[%d]->mapy : %d\n",
		map->i, map->sprite[map->i]->mapx, map->i, map->sprite[map->i]->mapy);
		sprite_xy(map);
		distance_sprite(map);
		sprite_invdet(map);
		sprite_transformxy(map);
		sprite_screenx(map);
		sprite_height(map);
		sprite_drawstarty(map);
		sprite_drawendy(map);
		sprite_width(map);
		sprite_drawstartx(map);
		sprite_drawendx(map);
		map->i++;
	}
	map->i = 0;
	printf("map->i : %d\n", map->i);
	while (map->i <= map->size_sprite)
	{
		sprite_loop(map);
		map->i++;
	}
}