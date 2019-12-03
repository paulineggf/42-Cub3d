/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/03 17:16:43 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		launch_game(t_map *map)
{
	draw_wall(0, map);
	mlx_key_hook(map->ptr->win, draw_wall, map);
	mlx_loop(map->ptr->mlx);
	return (1);
}
