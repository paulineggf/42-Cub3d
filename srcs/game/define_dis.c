/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_dis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:46:27 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/06 19:50:57 by pganglof         ###   ########.fr       */
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
	deltadistx = sqrt(1 + (map->gamer->raydiry * map->gamer->raydiry) / (map->gamer->raydirx * map->gamer->raydirx));
	deltadisty = sqrt(1 + (map->gamer->raydirx * map->gamer->raydirx) / (map->gamer->raydiry * map->gamer->raydiry));
	if (map->gamer->raydirx < 0)
	{
		map->gamer->stepx = -1;
		map->gamer->sidedistx = ((double)map->gamer->posx - (double)mapx) * deltadistx;
	}
	else
	{
		map->gamer->stepx = 1;
		map->gamer->sidedistx = ((double)mapx + 1.0 - (double)map->gamer->posx) * deltadistx;
	}
	if (map->gamer->raydiry < 0)
	{
		map->gamer->stepy = -1;
		map->gamer->sidedisty = ((double)map->gamer->posy - (double)mapy) * deltadisty;
	}
	else
	{
		map->gamer->stepy = 1;
		map->gamer->sidedisty = ((double)mapy + 1.0 - (double)map->gamer->posy) * deltadisty;
	}
	while (hit == 0)
	{
		if (map->gamer->sidedistx < map->gamer->sidedisty)
		{
			map->gamer->sidedistx += deltadistx;
			mapx += map->gamer->stepx;
			side = 0;
		}
		else
		{
			map->gamer->sidedisty += deltadisty;
			mapy += map->gamer->stepy;
			side = 1;
		}
		printf("map->x : %d && map->y : %d\n", map->x, map->y);
		printf("posy : %f && posy : %f\n", map->gamer->posx, map->gamer->posy);
		printf("mapx : %d && mapy : %d\n", mapx, mapy);
		printf("map->map[%d][%d] = %d\n", mapy, mapx, map->map[mapy][mapx]);
		if (map->map[mapy][mapx] == 1)
			hit = 1;
		printf("hit = %d\n", hit);
	}
	printf("side : %d\n", side);
	define_diswall(map, side, mapx - 1, mapy - 1);
	define_height(map);
	define_color(map, side);
	printf("--------------------------------------------------\n");
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
	}
	return ;*/
	map->gamer->beta = 30;
	x = 0;
	while (x < RES_X)
	{

		map->gamer->camerax = 2.0 * (((double)x) / ((double)RES_X - 1.0));
	//	map->gamer->raydirx = (map->gamer->dirx + map->gamer->planex)
	//	* x;
	//	map->gamer->raydiry = (map->gamer->diry + map->gamer->planey)
	//	* x;
		map->gamer->raydirx = (map->gamer->dirx + map->gamer->planex)
		* map->gamer->camerax;
		map->gamer->raydiry = (map->gamer->diry + map->gamer->planey)
		* map->gamer->camerax;
		printf("raydirx : %f && raydiry : %f\n", map->gamer->raydirx, map->gamer->raydiry);
		define_wall(map);
		while (map->gamer->drawstart <= map->gamer->drawend)
		{
			str[((map->ptr->size_l / 4) * map->gamer->drawstart)
			+ x] = map->ptr->color;
			map->gamer->drawstart += 1;
		}
		//x += 0.66 / (double)RES_X;
		x++;
		map->gamer->stepx = 0;
		map->gamer->stepy = 0;
		map->gamer->sidedistx = 0.0;
		map->gamer->sidedisty = 0.0;
		map->gamer->beta -= 0.66 / (double)RES_X;
	}
}
