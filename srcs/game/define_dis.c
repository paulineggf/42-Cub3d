/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_dis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:46:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/07 19:26:19 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		define_wall(t_map *map)
{
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		hit;
	int		side;

	hit = 0;
	mapx = (int)map->gamer->posx;
	mapy = (int)map->gamer->posy;
	//deltadistx = sqrt(1 + (map->gamer->raydiry * map->gamer->raydiry)
	/// (map->gamer->raydirx * map->gamer->raydirx));
	//deltadisty = sqrt(1 + (map->gamer->raydirx * map->gamer->raydirx)
	/// (map->gamer->raydiry * map->gamer->raydiry));
	//printf("deltax %f\n", deltadistx);
	//printf("deltay %f\n", deltadisty);
	deltadistx = fabs(1 / map->gamer->raydirx);
//	printf("deltax %f\n", deltadistx);
	deltadisty = fabs(1 / map->gamer->raydiry);
//	printf("deltay %f\n", deltadisty);
	if (map->gamer->raydirx < 0)
	{
	//	printf("raydirx < 0\n");
		map->gamer->stepx = -1;
		map->gamer->sidedistx = (map->gamer->posx - mapx)
		* deltadistx;
	}
	else
	{
	//	printf("raydirx > 0\n");
		map->gamer->stepx = 1;
		map->gamer->sidedistx = (mapx + 1.0 - map->gamer->posx)
		* deltadistx;
	}
	if (map->gamer->raydiry < 0)
	{
	//	printf("raydiry < 0\n");
		map->gamer->stepy = -1;
	//	map->gamer->sidedisty = (mapy + 1.0 - map->gamer->posy)
	//	* deltadisty;
		map->gamer->sidedisty = (map->gamer->posy - mapy)
		* deltadisty;
	}
	else
	{
		//printf("raydiry > 0\n");
		map->gamer->stepy = 1;
	//	map->gamer->sidedisty = (mapy + 1.0 - map->gamer->posy)
	//	* deltadisty;
		map->gamer->sidedisty = (mapy + 1.0 - map->gamer->posy)
		* deltadisty;
	}
/*	printf("sidedistx : %f\n", map->gamer->sidedistx);
	printf("sidedisty : %f\n", map->gamer->sidedisty);
	printf("stepx : %d %% stepy : %d\n", map->gamer->stepx, map->gamer->stepy);*/
	while (hit == 0)
	{
		if (map->gamer->sidedistx < map->gamer->sidedisty)
		{
		//	printf("Here X\n");
			map->gamer->sidedistx += deltadistx;
			mapx += map->gamer->stepx;
			side = 0;
		}
		else
		{
		//	printf("Here Y\n");
			map->gamer->sidedisty += deltadisty;
			mapy += map->gamer->stepy;
			side = 1;
		}
	/*	printf("map->x : %d && map->y : %d\n", map->x, map->y);
		printf("posy : %f && posy : %f\n", map->gamer->posx, map->gamer->posy);
		printf("mapx : %d && mapy : %d\n", mapx, mapy);
		printf("map->map[%d][%d] = %d\n", mapy, mapx, map->map[mapy][mapx]);*/
		if (map->map[mapy][mapx] == 1)
			hit = 1;
	/*	printf("sidedistx : %f\n", map->gamer->sidedistx);
		printf("sidedisty : %f\n", map->gamer->sidedisty);
		printf("stepx : %d %% stepy : %d\n", map->gamer->stepx, map->gamer->stepy);
		printf("hit = %d\n\n", hit);*/
	}
//	printf("side : %d\n", side);
	define_diswall(map, side, mapx, mapy);
	define_height(map);
	define_color(map, side);
//	printf("--------------------------------------------------\n");
}

void			define_dis(t_map *map, unsigned int *str)
{
	int		x;

	x = 0;
/*	int	i = 0;
	int	j = 0;
	printf("map->x : %d\n", map->x);
	printf("map->y : %d\n", map->y);
	printf("n - 48 : %d\n", '\n' - 48);
	printf("posx : %f && posy : %f\n", map->gamer->posx, map->gamer->posy);
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			printf("map[%d][%d] = %d\n", i, j, map->map[i][j]);
			j++;
		}
		i++;
	}*/
//	return ;
	//printf("dirx : %f && diry : %f\n", map->gamer->dirx, map->gamer->diry);
	map->gamer->beta = 30;
	x = 0;
	while (x < RES_X)
	{

		map->gamer->camerax = 2 * x / (double)RES_X - 1.0;
		map->gamer->raydirx = map->gamer->dirx + map->gamer->planex
								* map->gamer->camerax;
		map->gamer->raydiry = map->gamer->diry + map->gamer->planey
								* map->gamer->camerax;
		//printf("raydirx : %f && raydiry : %f\n",
		//map->gamer->raydirx, map->gamer->raydiry);
	//	break;
		define_wall(map);
		while (map->gamer->drawstart <= map->gamer->drawend)
		{
			str[((map->ptr->size_l / 4) * map->gamer->drawstart)
			+ x] = map->ptr->color;
			map->gamer->drawstart += 1;
		}
	//	break;
	//	printf("x : %d\n", x);
		x++;
		map->gamer->stepx = 0;
		map->gamer->stepy = 0;
	//	map->gamer->sidedistx = 0.0;
	//	map->gamer->sidedisty = 0.0;
		map->gamer->beta -= 60.0 / (double)RES_X;
	//	printf("beta : %f\n", map->gamer->beta);
	//	printf("disprojplane : %f\n", map->dis_proj_plane);
	}
}
