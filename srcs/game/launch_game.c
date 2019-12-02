/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:54 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 15:02:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// VERIF DU TEST ACTUEL --> FILL_WALL_VER AVEC LES TMP ETC
 
int		launch_game(t_map *map, t_pos *gamer, t_win *ptr)
{
	t_pos	*wall;
	int		i;

	i = 30;
	gamer->beta = 0;
	//gamer->degree += 30;

	map->ptr = ptr;

	//while (i >= -30)
	//{

	if (!(wall = is_wall(map, gamer)))
		return (0);
//	map->pos = wall;
//	printf("slice : %f\n", BLOCK_SIZE / dis_wall(gamer, wall)
//	* map->dis_proj_plane);

	wall->slice_height = roundf(((float)(BLOCK_SIZE)
	/ (float)(dis_wall(gamer, wall)) * (float)(map->dis_proj_plane)));
//	mlx_mouse_hook(ptr->win_ptr, draw_wall, map);

	//	gamer->degree--;
	//	i--;
	//}





//	map->ptr = ptr;
//	map->gamer = gamer;
//	draw_wall(0, map);
	//mlx_mouse_hook(ptr->win_ptr, draw_wall, map);
//	mlx_loop(ptr->mlx_ptr);
	return (1);
}
