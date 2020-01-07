/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_croix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:56:57 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/07 10:25:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_cross(int key, t_map *map)
{
	(void)key;
	(void)map;
	ft_putstr_fd("\n\n   --------- END OF GAME! ---------\n\n\n", 2);
	exit(0);
	return (0);
}
