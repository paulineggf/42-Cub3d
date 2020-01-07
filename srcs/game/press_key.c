/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/06 17:43:20 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Q = 12
** S = 1
** D = 2
** Z = 6
** ESC = 53
*/

int			press_key(int key, t_map *map)
{
	if (key == 12)
		map->gamer.forward = 1;
	if (key == 6)
		map->gamer.retreat = 1;
	if (key == 1)
		map->gamer.left = 1;
	if (key == 2)
		map->gamer.right = 1;
	if (key == 123)
		map->gamer.rotate_left = 1;
	if (key == 124)
		map->gamer.rotate_right = 1;
	if (key == 126)
		map->gamer.run = 1;
	if (key == 125)
		map->gamer.retreat_fast = 1;
	if (key == 49)
		map->gamer.jump = 30;
	if (key == 53)
	{
		mlx_destroy_image(map->ptr.mlx, map->ptr.img);
		mlx_destroy_window(map->ptr.mlx, map->ptr.win);
		exit_failure("\n\n   --------- END OF GAME! ---------\n\n\n", map);
	}
	return (1);
}
