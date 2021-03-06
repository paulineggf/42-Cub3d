/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:28:47 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/02 20:55:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_height(t_map *map)
{
	if (map->gamer.perpwalldist > 0)
		map->gamer.lineheight = (double)map->res_y / map->gamer.perpwalldist;
	else
		map->gamer.lineheight = ((double)map->res_y - 1.0);
	map->gamer.real_drawstart = (map->res_y / 2) - (map->gamer.lineheight / 2)
	+ map->gamer.tmp_jump;
	if (map->gamer.real_drawstart <= 0)
		map->gamer.drawstart = 0;
	else
		map->gamer.drawstart = map->gamer.real_drawstart;
	map->gamer.drawend = map->gamer.drawstart + map->gamer.lineheight;
	if (map->gamer.drawend >= map->res_y)
		map->gamer.drawend = map->res_y - 1;
}
