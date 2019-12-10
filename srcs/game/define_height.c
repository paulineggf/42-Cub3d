/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_height.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:28:47 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/10 15:22:08 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	define_height(t_map *map)
{
	if (map->gamer->perpwalldist > 0)
		map->gamer->lineheight = (double)RES_Y / map->gamer->perpwalldist;
	else
		map->gamer->lineheight = ((double)RES_Y - 1.0);
	map->gamer->drawstart = (RES_Y / 2) - (map->gamer->lineheight / 2);
	if (map->gamer->drawstart <= 0)
		map->gamer->drawstart = 0;
	map->gamer->drawend = map->gamer->drawstart + map->gamer->lineheight;
	if (map->gamer->drawend >= RES_Y)
		map->gamer->drawend = RES_Y - 1;
}
