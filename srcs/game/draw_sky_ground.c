/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_ground.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:38:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 15:42:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky_ground(t_map *map)
{
	int		x;
	int		sky;
	int		ground;

	x = 0;
	sky = 0x87CEEB;
	ground = 0x32CD32;
	while (x < ((map->ptr->size_l / 4) * RES_Y) / 2)
	{
		map->ptr->str[x] = sky;
		x += 1;
	}
	while (x < (map->ptr->size_l / 4) * (RES_Y))
	{
		map->ptr->str[x] = ground;
		x += 1;
	}
}
