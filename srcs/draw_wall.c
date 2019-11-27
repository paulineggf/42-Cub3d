/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:41:13 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 19:13:32 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_wall(int key, void *param)
{
	t_win	*ptr;

	(void)key;
	if (!(ptr = malloc(sizeof(ptr))))
		return (0);
	ft_bzero(ptr, sizeof(ptr));
	printf("%x\n", (((t_win*)((t_map*)(param))->ptr))->color);
	ptr = ((t_map*)(param))->ptr;
	printf("ptr->color : %x\n", ptr->color);
	/*while (gamer->beta >= -30)
	{
		if (!(wall = is_wall(map, gamer)))
			return (0);
		slice_height = BLOCK_SIZE / dis_wall(gamer, wall) * map->dis_proj_plane;
		//mlx_pixel_put((void*)&key, p->win_ptr, p->i, p->x, p->color);
	}*/
	return (1);
}
