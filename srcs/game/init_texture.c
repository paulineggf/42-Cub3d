/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/10 19:14:53 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_map *map)
{
	t_win	*text;

	if (!(text = malloc(sizeof(t_win))))
		return ;
	ft_bzero(text, sizeof(t_win));
	map->text = text;
	map->text->x = 64;
	map->text->y = 64;
	if (!(map->text->img = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures/wood.xpm", &map->text->x, &map->text->y)))
		return ;
	map->text->str = (unsigned int*)mlx_get_data_addr(map->text->img,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
}
