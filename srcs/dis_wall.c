/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:47:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/27 18:35:43 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dis_wall(t_pos *gamer, t_pos *wall)
{


	printf("%f\n", (sqrt(ft_iterative_power(*(int*)gamer->unitx - *(int*)wall->unitx, 2)
	+ ft_iterative_power(*(int*)gamer->unity - *(int*)wall->unity, 2))
	* cos(gamer->beta)));

	return (sqrt(ft_iterative_power(*(int*)gamer->unitx - *(int*)wall->unitx, 2)
	+ ft_iterative_power(*(int*)gamer->unity - *(int*)wall->unity, 2))
	* cos(gamer->beta));
	/*	return ((abs(*(int*)gamer->unitx - *(int*)wall->unitx)
	/ cos(ALPHA * M_PI / 180)) + (abs(*(int*)gamer->unity - *(int*)wall->unity)
	/ sin(ALPHA * M_PI / 180)) * cos(gamer->beta));*/
}
