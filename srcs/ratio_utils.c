/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:02 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:03 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_ratio1(t_data *data)
{
	data->r.p.rtexx = data->rx / data->r.p.h;
	data->r.p.rtexy = data->ry / data->r.p.w;
	data->r.m.rtexx = data->rx / data->r.m.h;
	data->r.m.rtexy = data->ry / data->r.m.w;
	data->r.l.rtexx = data->rx / data->r.l.h;
	data->r.l.rtexy = data->ry / data->r.l.w;
	data->r.s.rtexx = data->rx / data->r.s.h;
	data->r.s.rtexy = data->ry / data->r.s.w;
	data->b.p.rtexx = data->rx / data->b.p.h;
	data->b.p.rtexy = data->ry / data->b.p.w;
	data->b.m.rtexx = data->rx / data->b.m.h;
	data->b.m.rtexy = data->ry / data->b.m.w;
	data->b.l.rtexx = data->rx / data->b.l.h;
	data->b.l.rtexy = data->ry / data->b.l.w;
	data->b.s.rtexx = data->rx / data->b.s.h;
	data->b.s.rtexy = data->ry / data->b.s.w;
	data->g.p.rtexx = data->rx / data->g.p.h;
	data->g.p.rtexy = data->ry / data->g.p.w;
	data->g.m.rtexx = data->rx / data->g.m.h;
	data->g.m.rtexy = data->ry / data->g.m.w;
	data->g.l.rtexx = data->rx / data->g.l.h;
	data->g.l.rtexy = data->ry / data->g.l.w;
	data->g.s.rtexx = data->rx / data->g.s.h;
	data->g.s.rtexy = data->ry / data->g.s.w;
}

void	get_ratio2(t_data *data)
{
	data->y.p.rtexx = data->rx / data->y.p.h;
	data->y.p.rtexy = data->ry / data->y.p.w;
	data->y.m.rtexx = data->rx / data->y.m.h;
	data->y.m.rtexy = data->ry / data->y.m.w;
	data->y.l.rtexx = data->rx / data->y.l.h;
	data->y.l.rtexy = data->ry / data->y.l.w;
	data->y.s.rtexx = data->rx / data->y.s.h;
	data->y.s.rtexy = data->ry / data->y.s.w;
	data->w.rtexx = data->rx / data->w.h;
	data->w.rtexy = data->ry / data->w.w;
	data->f.rtexx = data->rx / data->f.h;
	data->f.rtexy = data->ry / data->f.w;
	data->s.rtexx = data->rx / data->s.h;
	data->s.rtexy = data->ry / data->s.w;
	data->e.rtexx = data->rx / data->e.h;
	data->e.rtexy = data->ry / data->e.w;
	data->x.rtexx = data->rx / data->x.h;
	data->x.rtexy = data->ry / data->x.w;
	data->s.rtexx = data->f.rtexx;
	data->s.rtexy = data->f.rtexy;
	data->s.w = data->f.w;
	data->s.h = data->f.h;
}

void	get_colbox1(t_data *data)
{
	data->colbox.red.ax = 9 * data->r.p.rtexx;
	data->colbox.red.ay = 13 * data->r.p.rtexy;
	data->colbox.red.bx = 9 * data->r.p.rtexx;
	data->colbox.red.by = 53 * data->r.p.rtexy;
	data->colbox.red.cx = 52 * data->r.p.rtexx;
	data->colbox.red.cy = 13 * data->r.p.rtexy;
	data->colbox.red.dx = 52 * data->r.p.rtexx;
	data->colbox.red.dy = 53 * data->r.p.rtexy;
	data->colbox.blue.ax = 6 * data->b.p.rtexx;
	data->colbox.blue.ay = 8 * data->b.p.rtexy;
	data->colbox.blue.bx = 6 * data->b.p.rtexx;
	data->colbox.blue.by = 49 * data->b.p.rtexy;
	data->colbox.blue.cx = 52 * data->b.p.rtexx;
	data->colbox.blue.cy = 8 * data->b.p.rtexy;
	data->colbox.blue.dx = 52 * data->b.p.rtexx;
	data->colbox.blue.dy = 49 * data->b.p.rtexy;
	data->colbox.green.ax = 5 * data->g.p.rtexx;
	data->colbox.green.ay = 9 * data->g.p.rtexy;
	data->colbox.green.bx = 5 * data->g.p.rtexx;
	data->colbox.green.by = 49 * data->g.p.rtexy;
	data->colbox.green.cx = 51 * data->g.p.rtexx;
	data->colbox.green.cy = 9 * data->g.p.rtexy;
	data->colbox.green.dx = 51 * data->g.p.rtexx;
	data->colbox.green.dy = 49 * data->g.p.rtexy;
}

void	get_colbox2(t_data *data)
{
	data->colbox.yellow.ax = 9 * data->y.p.rtexx;
	data->colbox.yellow.ay = 10 * data->y.p.rtexy;
	data->colbox.yellow.bx = 9 * data->y.p.rtexx;
	data->colbox.yellow.by = 50 * data->y.p.rtexy;
	data->colbox.yellow.cx = 51 * data->y.p.rtexx;
	data->colbox.yellow.cy = 10 * data->y.p.rtexy;
	data->colbox.yellow.dx = 51 * data->y.p.rtexx;
	data->colbox.yellow.dy = 50 * data->y.p.rtexy;
	data->sp_box.ax = 10 * data->s.rtexx;
	data->sp_box.ay = 8 * data->s.rtexy;
	data->sp_box.bx = 10 * data->s.rtexx;
	data->sp_box.by = (60 - 53) * data->s.rtexy;
	data->sp_box.cx = (60 - 52) * data->s.rtexx;
	data->sp_box.cy = 8 * data->s.rtexy;
	data->sp_box.dx = (60 - 52) * data->s.rtexx;
	data->sp_box.dy = (60 - 53) * data->s.rtexy;
}

void	get_all_ratio(t_data *data)
{
	get_ratio1(data);
	get_ratio2(data);
	get_colbox1(data);
	get_colbox2(data);
}
