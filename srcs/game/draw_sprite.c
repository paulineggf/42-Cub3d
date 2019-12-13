/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:07 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 20:00:31 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_map *map)
{
	int		xtext;
	int		ytext;
	int		i;
	int		drawstarty;
	int		drawendy;

	map->i = 0;
	while (map->i <= map->size_sprite)
	{
		distance_sprite(map);
		map->sprite[map->i]->spritex =
		map->sprite[map->i]->mapx - map->gamer.posx;
		map->sprite[map->i]->spritey =
		map->sprite[map->i]->mapy - map->gamer.posy;
		map->sprite[map->i]->indvet = 1.0 / (map->gamer.planex *
		map->gamer.diry - map->gamer.dirx * map->gamer.planey);
		map->sprite[map->i]->transformx = map->sprite[map->i]->indvet
		* (map->gamer.diry * map->sprite[map->i]->spritex
		- map->gamer.dirx * map->sprite[map->i]->spritey);
		map->sprite[map->i]->transformy = map->sprite[map->i]->indvet
		* ((map->gamer.planey * -1) * map->sprite[map->i]->spritex
		+ map->gamer.planex * map->sprite[map->i]->spritey);
		map->sprite[map->i]->screenx = (int)((RES_X / 2) * (1 +
		map->sprite[map->i]->transformx / map->sprite[map->i]->transformy));
		map->sprite[map->i]->height = abs((int)(RES_Y / map->sprite[map->i]->transformy));
		map->sprite[map->i]->drawstarty = (map->sprite[map->i]->height * -1) / 2 + RES_Y / 2;
		if (map->sprite[map->i]->drawstarty < 0)
			map->sprite[map->i]->drawstarty = 0;
		map->sprite[map->i]->drawendy = (map->sprite[map->i]->height / 2) + (RES_Y / 2);
		if (map->sprite[map->i]->drawendy >= RES_Y)
			map->sprite[map->i]->drawendy = RES_Y - 1;
		map->sprite[map->i]->width = abs((int)(RES_Y / map->sprite[map->i]->transformy));
		map->sprite[map->i]->drawstartx = ((map->sprite[map->i]->width * -1) / 2) + map->sprite[map->i]->screenx;
		if (map->sprite[map->i]->drawstartx < 0)
			map->sprite[map->i]->drawstartx = 0;
		map->sprite[map->i]->drawendx = map->sprite[map->i]->width / 2 + map->sprite[map->i]->screenx;
		if (map->sprite[map->i]->drawendx >= RES_X)
			map->sprite[map->i]->drawendx = RES_X - 1;
		map->i++;
	}
int	stripe;
int	textx;
int	texty;
int	y;
int d;
int	color;
	while (map->i-- >= 0)
	{
		stripe = map->sprite[map->i]->drawstartx;
		while (stripe < map->sprite[map->i]->drawendx)
		{
			textx = (int)(256 * (stripe - ((map->sprite[map->i]->width * -1)
			/ 2 + map->sprite[map->i]->screenx)) * map->text.sprite_x / map->sprite[map->i]->width);
			if (map->sprite[map->i]->transformy > 0 && stripe > 0 && stripe < RES_X)
			{
				y = map->sprite[map->i]->drawstarty;
				while (y < map->sprite[map->i]->drawendy)
				{
					d = (y)  * 256 - RES_Y * 128 + map->sprite[map->i]->height * 128;
					texty = ((d * map->text.sprite_y) / map->sprite[map->i]->height) / 256;
					color = map->text.str_sprite[map->text.sprite_x * texty + textx];
					map->ptr.str[((map->ptr.size_l / 4) * y) + stripe] = color;
					y++;
				}
			}
			stripe++;
		}
	}

}
