/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:49:55 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 17:32:09 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_wall(t_map *map)
{
	map->gamer->mapx = (int)map->gamer->posx;
	map->gamer->mapy = (int)map->gamer->posy;
	map->gamer->deltadistx = fabs(1 / map->gamer->raydirx);
	map->gamer->deltadisty = fabs(1 / map->gamer->raydiry);
	define_sidedistx(map);
	define_sidedisty(map);
	define_xy(map);
	define_diswall(map);
	define_height(map);
	define_wallx(map);
	define_color(map);
}
