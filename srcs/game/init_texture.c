/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 16:58:01 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_texture2(t_map *map)
{
	if (!(map->text->sky_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/Earth-globe-planet-space-world-1560003-wallhere.com.XPM",
	&map->text->sky_x, &map->text->sky_y)))
		exit_failure("Wrong Texture\n", map);
	map->text->sky = (unsigned int*)mlx_get_data_addr(map->text->sky_text,
	&map->text->b_p_sky, &map->text->size_l_sky, &map->text->endian_sky);
}

void		init_texture(t_map *map)
{
	t_win	*text;

	easy_malloc((void**)&text, sizeof(t_win), map);
	map->text = text;
	if (!(map->text->n_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/B_v-for-vend_nAkdIAig.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	map->text->str_n = (unsigned int*)mlx_get_data_addr(map->text->n_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	if (!(map->text->s_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon_vert.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	map->text->str_s = (unsigned int*)mlx_get_data_addr(map->text->s_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	if (!(map->text->e_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/EqdAgN.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	map->text->str_e = (unsigned int*)mlx_get_data_addr(map->text->e_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	if (!(map->text->w_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	map->text->str_w = (unsigned int*)mlx_get_data_addr(map->text->w_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian);
	init_texture2(map);
}
