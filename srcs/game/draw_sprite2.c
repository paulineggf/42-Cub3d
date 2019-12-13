/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:43:28 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_map *map)
{
	double	distance;
	double	height;
	double	drawstarty;
	double	lineheight;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double 	transformy;
	int 	spritescreenx;
	int drawendy;
	int drawendx;
	int drawstarty;
	int drawstartx;
	int spritewidth;

	map->gamer.i_sprite--;
	distance = ((map->gamer.posx - map->gamer.sprite[map->gamer.i_sprite][0])
	* (map->gamer.posx - map->gamer.sprite[map->gamer.i_sprite][0])
	+ (map->gamer.posy - map->gamer.sprite[map->gamer.i_sprite][1])
	* (map->gamer.posy - map->gamer.sprite[map->gamer.i_sprite][1]));
	
	spritex = map->gamer.sprite[map->gamer.i_sprite][0] - map->gamer.posx;
	spritey = map->gamer.sprite[map->gamer.i_sprite][1] - map->gamer.posy;
	
	invdet = 1.0 / (map->gamer.planex * map->gamer.diry - map->gamer.dirx * map->gamer.planey); 

	transformx = invdet * (map->gamer.diry * spritex - map->gamer.dirx * spritey);
    transformy = invdet * (-map->gamer.planey * spritex + map->gamer.planex * spritey); 

	spritescreenx = (int)((RES_X / 2) * (1 + transformx / transformy));
	height = abs((int)(RES_Y / (transformy)));

	drawstarty = -height / 2 + RES_Y / 2;
	if (drawstarty < 0)
		drawstarty = 0;
	drawendy = height / 2 + RES_Y / 2;
	if (drawendy >= RES_Y)
		drawendy = RES_Y - 1;

	spritewidth = abs((int)(RES_Y / (transformy)));
    drawstartx = -spritewidth / 2 + spritescreenx;
	if(drawstartx < 0) 
		drawstartx = 0;
	drawendx = spritewidth / 2 + spritescreenx;
	if(drawendx >= RES_X)
		drawendx = RES_X - 1;



}
