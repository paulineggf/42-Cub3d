/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:20:26 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/18 15:22:01 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	malloc_texture(t_map *map)
{
	int		i;

	easy_malloc((void**)&map->text, sizeof(t_win*) * 7, map);
	i = 0;
	while (i < 7)
	{
		easy_malloc((void**)&map->text[i], sizeof(t_win), map);
		i++;
	}
}
