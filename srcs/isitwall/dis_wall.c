/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:47:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/29 19:52:50 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dis_wall(t_pos *gamer, t_pos *wall)
{
	if (gamer->facing_up && gamer->facing_right)
		return (fabs(((wall->unitx - gamer->unitx) / cos((gamer->degree) * M_PI / 180)) * (cos(gamer->beta * M_PI / 180))));
	if (gamer->facing_up && gamer->facing_left)
		return (fabs(((gamer->unitx - wall->unitx) / cos((180 - gamer->degree) * M_PI / 180)) * (cos(gamer->beta * M_PI / 180))));
	if (gamer->facing_down && gamer->facing_right)
		return (fabs(((wall->unitx - gamer->unitx) / cos((360 - gamer->degree) * M_PI / 180)) * (cos(gamer->beta * M_PI / 180))));
	if (gamer->facing_down && gamer->facing_left)
		return (fabs(((gamer->unitx - wall->unitx) / cos((gamer->degree - 180) * M_PI / 180)) * (cos(gamer->beta * M_PI / 180))));
	return (0);


}
