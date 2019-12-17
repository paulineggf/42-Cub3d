/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:45:53 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/17 17:03:30 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_loop(t_map *map)
{
	int		stripe;
	int		textx;
	int		texty;
	int		y;
	int		d;
	int		color;

	stripe = map->sprite[map->i]->drawstartx;
	while (stripe < map->sprite[map->i]->drawendx)
	{
		textx = (256 * (stripe - ((map->sprite[map->i]->width * -1 / 2) +
		map->sprite[map->i]->screenx)) * map->text.sprite_x /
		map->sprite[map->i]->width) / 256;
		y = map->sprite[map->i]->drawstarty;
		while (y < map->sprite[map->i]->drawendy)
		{
			d = (y * 256) - (RES_Y * 128) + + map->sprite[map->i]->height * 128;
			texty = ((d * map->text.sprite_y) / map->sprite[map->i]->height) / 256;
			color = map->text.str_sprite[(map->text.size_l_sprite / 4) * texty + textx];
			// printf("color : %x\n", color);
			if (color != 0)
				map->ptr.str[((map->ptr.size_l / 4) * y) + stripe] = color;
			y++;
		}

		stripe++;
	}
}
