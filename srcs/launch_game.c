/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 19:12:48 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		launch_game(t_map *map, t_pos *gamer)
{
	//t_pos	*wall;
	t_win	*ptr;
	//float	slice_height;

	gamer->beta = 30;
	if (!(ptr = malloc(sizeof(t_win))))
		return (0);
	ft_bzero(ptr, sizeof(ptr));
	//ptr->mlx_ptr = mlx_init();
	//ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
	//PROJ_PLANE_X, PROJ_PLANE_Y, "Cub3D");
	ptr->color = 0xFF6F8F;
	map->ptr = ptr;
	map->gamer = gamer;
	draw_wall(0, map);
	//mlx_mouse_hook(ptr->win_ptr, draw_wall, map);
	//mlx_loop(ptr->mlx_ptr);
	return (1);
}
