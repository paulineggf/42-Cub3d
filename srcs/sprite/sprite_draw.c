/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:03:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 18:37:01 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_draw(t_map *map)
{
	sprite_combsort(map);
	map->i = 0;
	while (map->i <= map->size_sprite &&
	(map->sprite[map->i]->mapx || map->sprite[map->i]->mapx))
	{
		sprite_xy(map);
		// sprite_distance(map);
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
	while (map->i <= map->size_sprite &&
	(map->sprite[map->i]->mapx || map->sprite[map->i]->mapx))
	{
		sprite_loop(map);
		map->i++;
	}
}
