/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:46:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 14:39:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			fill_str(t_map *map)
{
	ft_bzero(map->zbuffer, sizeof(int) * RES_X);
	while (map->size_sprite-- > 0)
		ft_bzero(map->sprite[map->size_sprite], sizeof(t_sprite));
	map->size_sprite = 0;
	map->stripe = 0;
	while (map->stripe < RES_X)
	{
		map->gamer.camerax = 2.0 * (double)map->stripe / (double)RES_X - 1.0;
		map->gamer.raydirx = map->gamer.dirx + map->gamer.planex
								* map->gamer.camerax;
		map->gamer.raydiry = map->gamer.diry + map->gamer.planey
								* map->gamer.camerax;
		draw_sky_ground(map);
		define_wall(map);
		draw_wall(map);
		map->stripe++;
	}
	sprite_draw(map);
}
