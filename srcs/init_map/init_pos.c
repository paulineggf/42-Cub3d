/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:54:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 16:18:05 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_pos(t_pos *gamer, int orientation, int x, int y)
{
	gamer->posx = x;
	gamer->posy = y;
	if (orientation == 'N')
		gamer->degree = 90;
	if (orientation == 'E')
		gamer->degree = 0;
	if (orientation == 'W')
		gamer->degree = 180;
	if (orientation == 'S')
		gamer->degree = 270;
	if (gamer->degree >= 0 && gamer->degree < 180)
		gamer->facing_up = 1;
	if (gamer->degree >= 180 && gamer->degree < 360)
		gamer->facing_down = 1;
	if (gamer->degree <= 90 || gamer->degree > 270)
		gamer->facing_right = 1;
	*(int*)(gamer->unitx) = (gamer->posx * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	*(int*)(gamer->unity) = (gamer->posy * BLOCK_SIZE) + (BLOCK_SIZE / 2);
}
