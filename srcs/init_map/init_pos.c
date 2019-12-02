/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:54:32 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/02 14:55:46 by pganglof         ###   ########.fr       */
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
	gamer->degree = 180;
	if (gamer->degree >= 0 && gamer->degree < 180)
		gamer->facing_up = 1;
	if (gamer->degree >= 180 && gamer->degree < 360)
		gamer->facing_down = 1;
	if (gamer->degree <= 90 || gamer->degree > 270)
		gamer->facing_right = 1;
	if (gamer->degree > 90 && gamer->degree <= 270)
		gamer->facing_left = 1;
	gamer->unitx = (int)(gamer->posx * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	gamer->unity = (int)(gamer->posy * BLOCK_SIZE) + (BLOCK_SIZE / 2);
}
