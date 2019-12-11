/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/11 18:33:53 by pganglof         ###   ########.fr       */
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
	if (!(map->text->n_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/B_v-for-vend_nAkdIAig.xpm", &map->text->x, &map->text->y)))
		return ;
	map->text->str_n = (unsigned int*)mlx_get_data_addr(map->text->n_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	if (!(map->text->s_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon_vert.xpm", &map->text->x, &map->text->y)))
		return ;
	map->text->str_s = (unsigned int*)mlx_get_data_addr(map->text->s_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	if (!(map->text->e_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/EqdAgN.xpm", &map->text->x, &map->text->y)))
		return ;
	map->text->str_e = (unsigned int*)mlx_get_data_addr(map->text->e_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);

	if (!(map->text->w_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon.xpm", &map->text->x, &map->text->y)))
		return ;
	map->text->str_w = (unsigned int*)mlx_get_data_addr(map->text->w_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);

	 if (!(map->text->sky_text = mlx_xpm_file_to_image(map->ptr->mlx,
	 "./textures_hi/moon.xpm", &map->text->sky_x, &map->text->sky_y)))
	 	return ;
	 map->text->sky = (unsigned int*)mlx_get_data_addr(map->text->sky_text,
	 &map->text->b_p_sky, &map->text->size_l_sky, &map->text->endian_sky);
}
