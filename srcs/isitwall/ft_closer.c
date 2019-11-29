/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:04:39 by pganglof          #+#    #+#             */
/*   Updated: 2019/11/29 19:09:47 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	*ft_closer(t_pos *gamer, t_pos *wall_hor, t_pos *wall_ver)
{
	if (gamer->degree == 90 || gamer->degree == 270)
		return (free_wall(wall_hor, wall_ver));
	if (gamer->degree == 0 || gamer->degree == 180)
		return (free_wall(wall_ver, wall_hor));
	if (gamer->facing_right)
		return (free_wall((wall_hor->posx < wall_ver->posx ?
		(wall_hor) : (wall_ver)),
		wall_hor->posx < wall_ver->posx ? (wall_ver) : (wall_hor)));
	else
		return (free_wall((wall_hor->posx > wall_ver->posx ?
		(wall_hor) : (wall_ver)),
		wall_hor->posx > wall_ver->posx ? (wall_ver) : (wall_hor)));
}
