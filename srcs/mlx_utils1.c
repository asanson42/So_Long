/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:40 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:03:41 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_exitsprite(t_data *d)
{
	if (d->exit == 1)
	{
		if (d->bm[(int)((d->px * d->rx) + (d->rx / 2))]
				[(int)((d->py * d->ry) + (d->ry / 2))] == 'E')
			d->finished = 1;
	}
	else if (d->map.map[(int)d->px][(int)d->py] == 'c')
	{
		if (d->bm[(int)((d->px * d->rx) + (d->rx / 2))]
				[(int)((d->py * d->ry) + (d->ry / 2))] == 'c')
		{
			d->sprite_count++;
			d->map.map[(int)d->px][(int)d->py] = '0';
			d->bm = new_map(d->map, d);
		}
		if (d->sprite_count == d->num_sprites)
			d->exit = 1;
	}
}

void	init_colbox(t_data *data, t_box *box, t_box *sp)
{
	data->ax = box->ax;
	data->ay = box->ay;
	data->bx = box->bx;
	data->by = box->by;
	data->cx = box->cx;
	data->cy = box->cy;
	data->dx = box->dx;
	data->dy = box->dy;
	data->spax = sp->ax;
	data->spay = sp->ay;
	data->spbx = sp->bx;
	data->spby = sp->by;
	data->spcx = sp->cx;
	data->spcy = sp->cy;
	data->spdx = sp->dx;
	data->spdy = sp->dy;
}

void	dup_img(t_img *old, t_img *n)
{
	old->p = n->p;
	old->ad = n->ad;
	old->bp = n->bp;
	old->ln = n->ln;
	old->e = n->e;
	old->rtexx = n->rtexx;
	old->rtexy = n->rtexy;
	old->w = n->w;
	old->h = n->h;
}

void	choose_p(t_data *data, t_player *player, t_box *box)
{
	dup_img(&data->play, &player->p);
	dup_img(&data->move, &player->m);
	dup_img(&data->left, &player->l);
	dup_img(&data->mleft, &player->s);
	init_colbox(data, box, &data->sp_box);
}

void	choose_player(t_data *data)
{
	if (data->c_char == 1)
		choose_p(data, &data->b, &data->colbox.blue);
	if (data->c_char == 2)
		choose_p(data, &data->g, &data->colbox.green);
	if (data->c_char == 3)
		choose_p(data, &data->y, &data->colbox.yellow);
	if (data->c_char == 4)
		choose_p(data, &data->r, &data->colbox.red);
}
