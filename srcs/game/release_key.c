/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:09:56 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/07 19:33:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		release_key(int key, void *param)
{
	t_map			*map;

	map = (t_map*)param;
	if (key == 12)
		map->gamer->av = 0;
	if (key == 6)
		map->gamer->re = 0;
	if (key == 1)
		map->gamer->ga = 0;
	if (key == 2)
		map->gamer->dr = 0;
	if (key == 123)
		map->gamer->rga = 0;
	if (key == 124)
		map->gamer->rdr = 0;
	return (1);
}
