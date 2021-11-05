/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:02:59 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:03:01 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.map = NULL;
	map.x = 0;
	map.y = 0;
	map.p_x = 0;
	map.p_y = 0;
	map.e_x = 0;
	map.e_y = 0;
	map.sprite.sp = 0;
	map.sprite.x = NULL;
	map.sprite.y = NULL;
	map.set.player = 0;
	map.set.exit = 0;
	return (map);
}

void	init_img1(t_data *data)
{
	data->mlx = init_img();
	data->r.p = init_img();
	data->r.m = init_img();
	data->r.l = init_img();
	data->r.s = init_img();
	data->b.p = init_img();
	data->b.m = init_img();
	data->b.l = init_img();
	data->b.s = init_img();
	data->g.p = init_img();
	data->g.m = init_img();
	data->g.l = init_img();
	data->g.s = init_img();
	data->y.p = init_img();
	data->y.m = init_img();
	data->y.l = init_img();
	data->y.s = init_img();
}

void	init_img2(t_data *data)
{
	data->play = init_img();
	data->move = init_img();
	data->left = init_img();
	data->mleft = init_img();
	data->m.b = init_img();
	data->m.r = init_img();
	data->m.g = init_img();
	data->m.y = init_img();
	data->m.t = init_img();
	data->m.s = init_img();
	data->w = init_img();
	data->f = init_img();
	data->s = init_img();
	data->e = init_img();
	data->x = init_img();
	data->win = init_img();
}

void	init_cbox(t_data *data)
{
	data->colbox.red = init_box();
	data->colbox.blue = init_box();
	data->colbox.green = init_box();
	data->colbox.yellow = init_box();
	data->sp_box = init_box();
}
