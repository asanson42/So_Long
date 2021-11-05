/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:52 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:53 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_size(t_img *img, int w, int h)
{
	img->w = w;
	img->h = h;
}

static int	init_mlximg(t_data *data, t_img *img, char *path)
{
	int	w;
	int	h;

	img->p = mlx_xpm_file_to_image(data->mx, path, &w, &h);
	if (img->p == NULL)
	{
		printf("Error: textures failed.\n");
		ft_exit(data);
	}
	img->ad = mlx_get_data_addr(img->p, &img->bp, &img->ln, &img->e);
	init_size(img, w, h);
	return (0);
}

void	get_main_textures(t_data *d)
{
	init_mlximg(d, &d->w, "./t/w.xpm");
	init_mlximg(d, &d->f, "./t/f.xpm");
	init_mlximg(d, &d->e, "./t/ce.xpm");
	init_mlximg(d, &d->x, "./t/oe.xpm");
	init_mlximg(d, &d->s, "./t/g.xpm");
	init_mlximg(d, &d->m.y, "./t/yd.xpm");
	init_mlximg(d, &d->m.g, "./t/gd.xpm");
	init_mlximg(d, &d->m.b, "./t/bd.xpm");
	init_mlximg(d, &d->m.r, "./t/rd.xpm");
	init_mlximg(d, &d->m.s, "./t/sc.xpm");
	init_mlximg(d, &d->m.t, "./t/t.xpm");
	init_mlximg(d, &d->win, "./t/e.xpm");
}

void	get_player_textures(t_data *d)
{
	init_mlximg(d, &d->r.p, "./t/sr.xpm");
	init_mlximg(d, &d->r.m, "./t/wr.xpm");
	init_mlximg(d, &d->r.l, "./t/rl.xpm");
	init_mlximg(d, &d->r.s, "./t/rw.xpm");
	init_mlximg(d, &d->b.p, "./t/sb.xpm");
	init_mlximg(d, &d->b.m, "./t/wb.xpm");
	init_mlximg(d, &d->b.s, "./t/bl.xpm");
	init_mlximg(d, &d->b.l, "./t/bw.xpm");
	init_mlximg(d, &d->g.p, "./t/sg.xpm");
	init_mlximg(d, &d->g.m, "./t/wg.xpm");
	init_mlximg(d, &d->g.l, "./t/gl.xpm");
	init_mlximg(d, &d->g.s, "./t/gw.xpm");
	init_mlximg(d, &d->y.p, "./t/sy.xpm");
	init_mlximg(d, &d->y.m, "./t/wy.xpm");
	init_mlximg(d, &d->y.l, "./t/yl.xpm");
	init_mlximg(d, &d->y.s, "./t/yw.xpm");
}

int	get_texture(t_data *d)
{
	get_player_textures(d);
	get_main_textures(d);
	if (d->w.p == NULL || d->f.p == NULL || d->e.p == NULL
		|| d->x.p == NULL || d->s.p == NULL || d->m.y.p == NULL
		|| d->m.g.p == NULL || d->m.b.p == NULL || d->m.r.p == NULL
		|| d->m.s.p == NULL || d->m.t.p == NULL || d->win.p == NULL
		|| d->r.p.p == NULL || d->r.m.p == NULL || d->r.l.p == NULL
		|| d->r.s.p == NULL || d->b.p.p == NULL || d->b.m.p == NULL
		|| d->b.l.p == NULL || d->b.s.p == NULL || d->y.p.p == NULL
		|| d->y.m.p == NULL || d->y.l.p == NULL || d->y.s.p == NULL
		|| d->g.p.p == NULL || d->g.m.p == NULL
		|| d->g.l.p == NULL || d->g.s.p == NULL)
	{
		printf("Xpm file error.\n");
		ft_exit(d);
		return (0);
	}
	return (1);
}
