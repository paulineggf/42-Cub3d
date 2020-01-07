/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:13:26 by pganglof          #+#    #+#             */
/*   Updated: 2020/01/05 18:00:41 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_texture(char *str, int i, char **texture, t_map *map)
{
	while (str[i] == ' ')
		i++;
	easy_malloc((void**)texture, sizeof(char) *
	(ft_strnlen(str + i, '\0') + 1), map);
	ft_strcpy(*texture, str + i);
}
