/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:59:42 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/03 13:29:52 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_image(t_map *map)
{
	if (!(move_gamer(map)))
		return (0);
	if (map->gamer.jump > 0)
	{
		map->gamer.tmp2_jump = 0;
		map->gamer.tmp_jump += 4;
		map->gamer.jump--;
		if (map->gamer.jump == 0)
			map->gamer.tmp2_jump = 1;
	}
	if (map->gamer.tmp2_jump == 1)
	{
		map->gamer.tmp_jump -= 4;
		if (map->gamer.tmp_jump == 0)
			map->gamer.tmp2_jump = 0;
	}
	fill_str(map);
	mlx_put_image_to_window(map->ptr.mlx,
	map->ptr.win, map->ptr.img, 0, 0);
	return (1);
}
