/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:13:45 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/06 18:48:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		color(t_map *map, t_pos *wall)
{
	if (wall->hor)
		map->ptr->color = 0xF6582B;
	if (wall->ver)
		map->ptr->color = 0x174541;
/*	if (map->gamer->degree == 0)
		map->ptr->color = 0x6587FA;
	if (map->gamer->degree == 90)
		map->ptr->color = 0xF7F40F;
	if (map->gamer->degree == 180)
		map->ptr->color = 0xF60FF7;
	if (map->gamer->degree == 270)
		map->ptr->color = 0x39F70F;
	if (map->gamer->degree == 360)
		map->ptr->color = 0x358974;*/
}

static int		draw_wall3(t_map *map, unsigned int *str)
{
	int		tmp;
	t_pos	*wall;

	if (map->gamer->beta == 30)
		printf("degree 2: %f\n", map->gamer->degree);
	if (map->gamer->beta < 30 && map->gamer->beta > 29.50)	
	printf("map->hor : %d && map->ver : %d\n", map->hor, map->ver);	
	if (!(wall = is_wall(map)))
		return (0);
	
	//if (map->gamer->beta == 30)
	//	printf("wall->unitx : %f\nwall->unity : %f\n", wall->unitx, wall->unity);
	//if (wall->posx < 0 || wall->posx > map->x || wall->posy < 0 || wall->posy > map->y)
	//	printf("wall->unitx : %f\nwall->unity : %f\n", wall->unitx, wall->unity);
	wall->slice_height = (double)(BLOCK_SIZE)
	/ (wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)))
	* (map->dis_proj_plane);
	//printf("slice: %f\n", wall->slice_height);
	if (map->gamer->beta < 30 && map->gamer->beta > 29.50) //&& wall->hor)
	{
		printf("map->hor : %d && map->ver : %d\n", map->hor, map->ver);
		printf("gamer->unitx : %d\ngamer->unity : %d\n", map->gamer->unitx, map->gamer->unity);
		printf("gamer->posx : %d\ngamer->posy : %d\n", map->gamer->posx, map->gamer->posy);
		printf("up : %d\ndown : %d\nright : %d\nleft : %d\n", map->gamer->facing_up, map->gamer->facing_down, map->gamer->facing_right, map->gamer->facing_left);
		printf("degree 2: %f\n", map->gamer->degree);
		printf("wall->unitx : %d\nwall->unity : %d\nwall->posx : %d\nwall->posy : %d\n", wall->unitx, wall->unity, wall->posx, wall->posy);
		printf("wall->dis 1: %f\nwall->dis 2 : %f\n", wall->dis, wall->dis * cos((double)(map->gamer->beta * M_PI / 180.0)));
		printf("wall->slice_height : %f\n", wall->slice_height);
		if (wall->hor)
			printf("WALL HOR\n");
		if (wall->ver)
			printf("WALL VER\n");
		printf("beta : %f\n", map->gamer->beta);
	}
	map->ptr->y = (PROJ_PLANE_Y / 2) - (wall->slice_height / 2);
	if (map->gamer->beta < 30 && map->gamer->beta > 29.50) 
		printf("map->ptr->y : %d\n\n\n", map->ptr->y);
	if (map->ptr->y < 0 || map->ptr->y > PROJ_PLANE_Y)
		map->ptr->y = 0;
	color(map, wall);
	tmp = map->ptr->y;
	while (map->ptr->y <= tmp + wall->slice_height
	&& map->ptr->y < PROJ_PLANE_Y)
	{
		str[map->ptr->size_l / 4 * map->ptr->y
		+ map->ptr->x] = map->ptr->color;
		map->ptr->y += 1;
	}
	free(wall);
	wall = NULL;
	return (1);
}

int				draw_wall2(t_map *map, unsigned int *str)
{
	double	degree;

	degree = map->gamer->degree;
	map->gamer->degree += 30.0;
	map->ptr->x = 0;
	map->gamer->beta = 30.0;
	while (map->ptr->x < PROJ_PLANE_X)
	{
		if (map->gamer->degree >= 360)
			map->gamer->degree -= 360;
		if (map->gamer->degree < 0)
			map->gamer->degree += 360;
	if (map->gamer->degree >= 0 && map->gamer->degree < 180)
		map->gamer->facing_up = 1;
	else
		map->gamer->facing_up = 0;
	if (map->gamer->degree >= 180 && map->gamer->degree < 360)
		map->gamer->facing_down = 1;
	else
		map->gamer->facing_down = 0;
	if (map->gamer->degree <= 90 || map->gamer->degree > 270)
		map->gamer->facing_right = 1;
	else
		map->gamer->facing_right = 0;
	if (map->gamer->degree > 90 && map->gamer->degree <= 270)
		map->gamer->facing_left = 1;
	else
		map->gamer->facing_left = 0;
		if (!(draw_wall3(map, str)))
			return (0);
		map->gamer->degree -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->gamer->beta -= (double)ALPHA / (double)PROJ_PLANE_X;
		map->ptr->x += 1;
	}
	map->gamer->degree = degree;
	return (1);
}
