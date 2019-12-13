/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:09:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/13 19:00:00 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		release_key(int key, void *param)
{
	t_map			*map;

	map = (t_map*)param;
	if (key == 12)
		map->gamer.forward = 0;
	if (key == 6)
		map->gamer.retreat = 0;
	if (key == 1)
		map->gamer.left = 0;
	if (key == 2)
		map->gamer.right = 0;
	if (key == 123)
		map->gamer.rotate_left = 0;
	if (key == 124)
		map->gamer.rotate_right = 0;
	return (1);
}
