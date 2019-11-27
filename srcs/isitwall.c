/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isitwall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:47:34 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 18:29:07 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		is_wallbis(t_pos *gamer, t_pos *wall)
{
	*(float*)wall->unitx = *(float*)(wall->unitx)
	+ (int)(BLOCK_SIZE / tan(ALPHA * M_PI / 180));
	if (gamer->facing_up)
		*(float*)wall->unity = *(float*)(wall->unity) + -BLOCK_SIZE;
	else
		*(float*)wall->unity = *(float*)(wall->unity) + BLOCK_SIZE;
	wall->posx = *(float*)wall->unitx / BLOCK_SIZE;
	wall->posy = *(float*)wall->unity / BLOCK_SIZE;
}

static void		fill_wall_hor(t_map *map, t_pos *gamer, t_pos *wall_hor)
{
	if (gamer->facing_up)
		*(float*)(wall_hor->unity) = (*(int*)(gamer->unity)
		/ BLOCK_SIZE) * (BLOCK_SIZE) - 1;
	else
		*(float*)(wall_hor->unity) = (*(int*)(gamer->unity) / BLOCK_SIZE)
		* (BLOCK_SIZE) + BLOCK_SIZE;
	*(float*)(wall_hor->unitx) = *(int*)(gamer->unitx)
	+ (*(int*)(gamer->unity) - *(float*)wall_hor->unity)
	/ tan(ALPHA * M_PI / 180);
	wall_hor->posx = *(float*)(wall_hor->unitx) / BLOCK_SIZE;
	wall_hor->posy = *(float*)(wall_hor->unity) / BLOCK_SIZE;
	while (map->map[wall_hor->posy][wall_hor->posx] == 0)
		is_wallbis(gamer, wall_hor);
}

static void		fill_wall_ver(t_map *map, t_pos *gamer, t_pos *wall_ver)
{
	if (gamer->facing_right)
		*(float*)(wall_ver->unitx) = (*(int*)(gamer->unitx)
		/ BLOCK_SIZE) * (BLOCK_SIZE) + BLOCK_SIZE;
	else
		*(float*)(wall_ver->unitx) = (*(int*)(gamer->unitx)
		/ BLOCK_SIZE) * (BLOCK_SIZE) - 1;
	*(float*)(wall_ver->unity) = *(int*)(gamer->unity) + (*(int*)(gamer->unitx)
	- *(float*)(wall_ver->unitx)) * tan(ALPHA * M_PI / 180);
	wall_ver->posx = *(float*)(wall_ver->unitx) / BLOCK_SIZE;
	wall_ver->posy = *(float*)(wall_ver->unity) / BLOCK_SIZE;
	while (map->map[wall_ver->posy][wall_ver->posx] == 0)
	{
		*(float*)wall_ver->unitx = *(float*)wall_ver->unitx + BLOCK_SIZE;
		*(float*)wall_ver->unity = *(float*)wall_ver->unity
		- (int)(BLOCK_SIZE * tan(ALPHA * M_PI / 180));
		wall_ver->posx = *(float*)(wall_ver->unitx) / BLOCK_SIZE;
		wall_ver->posy = *(float*)(wall_ver->unity) / BLOCK_SIZE;
	}
}

static t_pos	*ft_closer(t_pos *gamer, t_pos *wall_hor, t_pos *wall_ver)
{
	if (gamer->facing_up)
	{
		if (gamer->facing_right)
			return (free_wall((wall_hor->posx < wall_ver->posx ?
			(wall_hor) : (wall_ver)), (wall_hor->posx < wall_ver->posx ?
			(wall_ver) : (wall_hor))));
		else
			return (free_wall((wall_hor->posx > wall_ver->posx ?
			(wall_hor) : (wall_ver)), (wall_hor->posx > wall_ver->posx ?
			(wall_ver) : (wall_hor))));
	}
	else
	{
		if (gamer->facing_right)
			return (free_wall((wall_hor->posy < wall_ver->posy ?
			(wall_hor) : (wall_ver)), (wall_hor->posy < wall_ver->posy ?
			(wall_ver) : (wall_hor))));
		else
			return (free_wall((wall_hor->posy > wall_ver->posy ?
			(wall_hor) : (wall_ver)), (wall_hor->posy > wall_ver->posy ?
			(wall_ver) : (wall_hor))));
	}
}

t_pos			*is_wall(t_map *map, t_pos *gamer)
{
	t_pos	*wall_hor;
	t_pos	*wall_ver;

	if (!(wall_hor = malloc(sizeof(t_pos))))
		return (NULL);
	ft_bzero(wall_hor, sizeof(t_pos));
	if (!(wall_hor->unitx = ft_calloc(1, sizeof(float)))
	|| !(wall_hor->unity = ft_calloc(1, sizeof(float))))
		return (NULL);
	if (!(wall_ver = malloc(sizeof(t_pos))))
		return (NULL);
	ft_bzero(wall_ver, sizeof(t_pos));
	wall_ver->ver = 1;
	wall_hor->hor = 1;
	if (!(wall_ver->unitx = ft_calloc(1, sizeof(float)))
	|| !(wall_ver->unity = ft_calloc(1, sizeof(float))))
		return (NULL);
	fill_wall_hor(map, gamer, wall_hor);
	fill_wall_ver(map, gamer, wall_ver);
	return (ft_closer(gamer, wall_hor, wall_ver));
}
