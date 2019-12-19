/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:13:26 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/19 17:07:18 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		fill_texture(char *buf, int *i, char *texture, t_map *map)
{
	int		tmp;
	int		len_text;

	tmp = *i;
	while (buf[*i] == ' ')
		(*i)++;
	if (tmp == *i)
		return (0);
	len_text = ft_strnlen(buf + *i, '\n');
	easy_malloc((void**)&texture, len_text, map);
	ft_strncpy(texture, buf + *i, '\n');
	*i += len_text;
	return (1);
}
