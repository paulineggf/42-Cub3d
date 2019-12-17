/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:03:19 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 15:43:06 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_map *map)
{
	int		xtext;
	int		ytext;
	int		i;
	int		x;

	i = 0;
	map->i = 0;
	x = 200;
	while (map->i <= map->size_sprite)
	{
		sprite_xy(map);
		distance_sprite(map);
		invdet(map);
		transformxy(map);
		sprite_screenx(map);
		sprite_height(map);
		sprite_x(map);
		map->i++;
	}
	map->i--;
	while (map->i >= 0)
	{
		if (map->sprite[map->i]->real_drawstart < 0)
			i = abs(map->sprite[map->i]->real_drawstart);
		else
			i = 0;
		xtext = map->sprite[map->i]->x * map->text.sprite_x;
		while (x < 500)
		{
			while (map->sprite[map->i]->drawstart <= map->sprite[map->i]->drawend)
			{
				if (i * map->text.sprite_y / (int)map->sprite[map->i]->height >= map->text.sprite_y)
					ytext = map->text.sprite_y - 1;
				else
					ytext = i * map->text.sprite_y / (int)map->sprite[map->i]->height;
				map->ptr.str[((map->ptr.size_l / 4) * map->sprite[map->i]->drawstart)
				+ x] = map->text.str[(ytext * (map->text.size_l / 4)) + xtext];
				i++;
				map->sprite[map->i]->drawstart += 1;
			}
			x++;
		}
		map->i--;
	}
}
