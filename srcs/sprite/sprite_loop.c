/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:45:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 11:47:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		fill_str_sprite(t_map *map, int y, int *stripe, int *textx)
{
	int		d;
	int		texty;
	int		color;

	if (map->sprite[map->i]->transformy > 0 && *stripe > 0 &&
		*stripe < RES_X && map->sprite[map->i]->transformy
		< map->zbuffer[*stripe])
	{
		while (y < map->sprite[map->i]->drawendy)
		{
			d = y * 256 - RES_Y * 128 + map->sprite[map->i]->height * 128;
			texty = ((d * map->text[SPRITE]->y) / map->sprite[map->i]->height)
			/ 256;
			color = map->text[SPRITE]->str[(map->text[SPRITE]->size_l / 4)
			* texty + *textx];
			color = abs(color);
			if (color != 0xffffff)
				map->ptr.str[((map->ptr.size_l / 4) * y) + *stripe] = color;
			y++;
		}
	}
}

void			sprite_loop(t_map *map)
{
	int		stripe;
	int		textx;
	int		y;

	stripe = map->sprite[map->i]->drawstartx;
	while (stripe < map->sprite[map->i]->drawendx)
	{
		textx = (int)((256 * (stripe - ((map->sprite[map->i]->width * -1 / 2) +
		map->sprite[map->i]->screenx)) * map->text[SPRITE]->x /
		map->sprite[map->i]->width) / 256);
		y = map->sprite[map->i]->drawstarty;
		fill_str_sprite(map, y, &stripe, &textx);
		stripe++;
	}
}
