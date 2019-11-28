/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:47:21 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/28 18:43:14 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dis_wall(t_pos *gamer, t_pos *wall)
{
/*	printf("%f\n", sqrt(ft_iterative_power(*(int*)gamer->unitx - *(float*)wall->unitx, 2)
	+ ft_iterative_power(*(int*)gamer->unity - *(float*)wall->unity, 2))
	* cos(gamer->beta));

	printf("%f\n", BLOCK_SIZE / sqrt(ft_iterative_power(*(int*)gamer->unitx - *(float*)wall->unitx, 2)
	+ ft_iterative_power(*(int*)gamer->unity - *(float*)wall->unity, 2))
	* cos(gamer->beta) * 277);*/

	/*double ite;

	ite = (double)((double)(ft_iterative_power(*(int*)gamer->unitx - *(float*)wall->unitx, 2)
	+ (double)(ft_iterative_power(*(int*)gamer->unity - *(float*)wall->unity, 2))));

	printf("ite %f\n", ite);

	printf("sqrt %f\n", (float)sqrt(ite));


	printf("slice1 : %f\n", BLOCK_SIZE / (double)sqrt(ite) * 277);*/

	printf("TEST\n");

	printf("pow1 :%G\n", pow(*(int*)gamer->unitx - *(float*)wall->unitx, 2));
	
	printf("dis : %G\n", sqrt(pow((double)(*(int*)gamer->unitx - *(float*)wall->unitx), 2)
	+ pow((double)(*(int*)gamer->unity - *(float*)wall->unity), 2))
	* cos(gamer->beta * M_PI / 180));

	return (sqrt(pow((double)(*(int*)gamer->unitx - *(float*)wall->unitx), 2)
	+ pow((double)(*(int*)gamer->unity - *(float*)wall->unity), 2))
	* cos(gamer->beta * M_PI / 180));

/*	return ((double)sqrt((double)((double)(ft_iterative_power(*(int*)gamer->unitx - *(float*)wall->unitx, 2)
	+ (double)(ft_iterative_power(*(int*)gamer->unity - *(float*)wall->unity, 2))))
	* cos(gamer->beta)));*/
}
