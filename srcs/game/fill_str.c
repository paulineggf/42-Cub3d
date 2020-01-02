/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:46:27 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 21:24:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			fill_str(t_map *map)
{
	ft_bzero(map->zbuffer, sizeof(int) * map->res_x);
	while (map->size_sprite > 0)
	{
		ft_bzero(map->sprite[map->size_sprite], sizeof(t_sprite));
		map->size_sprite--;
	}
	map->stripe = 0;
	while (map->stripe < map->res_x)
	{
		map->gamer.camerax = 2.0 * (double)map->stripe /
		(double)map->res_x - 1.0;
		map->gamer.raydirx = map->gamer.dirx + map->gamer.planex
								* map->gamer.camerax;
		map->gamer.raydiry = map->gamer.diry + map->gamer.planey
								* map->gamer.camerax;
		draw_sky(map);
		define_wall(map);
		draw_wall(map);
		map->zbuffer[map->stripe] = map->gamer.perpwalldist;
		draw_floor(map);
		map->stripe++;
	}
	sprite_draw(map);
}
