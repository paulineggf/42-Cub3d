/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:46:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 18:30:54 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			fill_str(t_map *map)
{
	ft_bzero(map->zbuffer, RES_X);
	map->size_sprite = 0;
	map->stripe = 0;
	while (map->stripe < RES_X)
	{
		map->gamer.camerax = 2 * map->stripe / (double)RES_X - 1.0;
		map->gamer.raydirx = map->gamer.dirx + map->gamer.planex
								* map->gamer.camerax;
		map->gamer.raydiry = map->gamer.diry + map->gamer.planey
								* map->gamer.camerax;
		draw_sky_ground(map);
		define_wall(map);
		draw_wall(map);
		map->stripe++;
	}
	draw_sprite(map);
	// exit(0);
}
