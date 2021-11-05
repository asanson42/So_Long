/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:02:46 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:02:48 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_box	init_box(void)
{
	t_box	box;

	box.ax = 0;
	box.ay = 0;
	box.bx = 0;
	box.by = 0;
	box.cx = 0;
	box.cy = 0;
	box.dx = 0;
	box.dy = 0;
	return (box);
}

t_img	init_img(void)
{
	t_img	img;

	img.p = NULL;
	img.ad = NULL;
	img.bp = 0;
	img.ln = 0;
	img.e = 0;
	img.rtexx = 0;
	img.rtexy = 0;
	img.w = 0;
	img.h = 0;
	return (img);
}

void	init_data(t_data *data)
{
	data->mx = NULL;
	data->wptr = NULL;
	data->rx = 0;
	data->ry = 0;
	data->rtexx = 0;
	data->rtexy = 0;
	data->px = 0;
	data->py = 0;
	data->diry = 0;
	data->mvsd = 0;
	data->bm = NULL;
	data->end_screen = 0;
	data->is_main = 1;
	data->select_char = 0;
	data->c_char = 0;
	data->num_sprites = 0;
	data->sprite_count = 0;
	data->exit = 0;
	data->finished = 0;
	data->mvcount = 0;
}

t_data	init_all_data(void)
{
	t_data	data;

	init_data(&data);
	init_img1(&data);
	init_img2(&data);
	init_cbox(&data);
	data.map = init_map();
	return (data);
}
