/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:58:30 by pganglof          #+#    #+#             */
/*   Updated: 2019/12/12 18:32:55 by pganglof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_texture_sky(t_map *map)
{
	t_list	*sky;

	if (!(map->text->sky_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/Earth-globe-planet-space-world-1560003-wallhere.com.XPM",
	&map->text->sky_x, &map->text->sky_y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text->sky = (unsigned int*)mlx_get_data_addr(map->text->sky_text,
	&map->text->b_p_sky, &map->text->size_l_sky, &map->text->endian_sky)))
		exit_failure("Malloc failure\n", map);
	if (!(sky = ft_lstnew(map->text->sky)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), sky);
}

static void		init_texture3(t_map *map)
{
	t_list *new_s;

	if (!(map->text->s_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon_vert.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text->str_s = (unsigned int*)mlx_get_data_addr(map->text->s_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_s = ft_lstnew(map->text->str_s)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_s);
}

static void		init_texture2(t_map *map)
{
	t_list	*new_e;
	t_list	*new_w;

	if (!(map->text->e_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/EqdAgN.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text->str_e = (unsigned int*)mlx_get_data_addr(map->text->e_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_e = ft_lstnew(map->text->str_e)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_e);
	if (!(map->text->w_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/anon.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text->str_w = (unsigned int*)mlx_get_data_addr(map->text->w_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_w = ft_lstnew(map->text->str_w)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_w);
}

void			init_texture(t_map *map)
{
	t_win	*text;
	t_list	*new_n;

	easy_malloc((void**)&text, sizeof(t_win), map);
	map->text = text;
	if (!(map->text->n_text = mlx_xpm_file_to_image(map->ptr->mlx,
	"./textures_hi/B_v-for-vend_nAkdIAig.xpm", &map->text->x, &map->text->y)))
		exit_failure("Wrong Texture\n", map);
	if (!(map->text->str_n = (unsigned int*)mlx_get_data_addr(map->text->n_text,
	&map->text->b_p, &map->text->size_l, &map->text->endian)))
		exit_failure("Malloc failure\n", map);
	if (!(new_n = ft_lstnew(map->text->str_n)))
		exit_failure("Malloc failure\n", map);
	ft_lstadd_front(&(map->garbage_collector), new_n);
	init_texture2(map);
	init_texture3(map);
	init_texture_sky(map);
}
