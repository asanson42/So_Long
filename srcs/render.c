/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:08 by asanson           #+#    #+#             */
/*   Updated: 2021/10/29 17:17:08 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(t_data *data, t_img *img, int x, int y)
{
	int	i;
	int	j;
	int	color;
	int	sx;
	int	sy;

	i = y;
	sx = 0;
	while (i < y + img->h)
	{
		sy = 0;
		j = x;
		while (j < x + img->w)
		{
			color = get_pixel(img, sy, sx);
			if (color <= 0)
				color = ORANGE_PIX;
			img_pixel_put(&data->mlx, j, i, color);
			sy++;
			j++;
		}
		sx++;
		i++;
	}
}

void	render_main(t_data *d)
{
	render_background(d, ORANGE_PIX);
	mlx_put_image_to_window(d->mx, d->wptr, d->mlx.p, 0, 0);
	if (d->is_main == 1)
	{
		display_image(d, &d->m.t, WIN_W / 2 - (d->m.t.w / 2), \
			WIN_H / 2 - (d->m.t.h / 2));
		mlx_put_image_to_window(d->mx, d->wptr, d->mlx.p, 0, 0);
	}
	else if (d->is_main == 2)
	{
		display_image(d, &d->m.s, WIN_W / 2 - (d->m.s.w / 2), WIN_H / 3);
		display_image(d, &d->m.b, (WIN_W / 2) - (d->m.b.w * 3), WIN_H / 2);
		display_image(d, &d->m.g, (WIN_W / 2) - (d->m.g.w * 1.5), WIN_H / 2);
		display_image(d, &d->m.y, (WIN_W / 2), WIN_H / 2);
		display_image(d, &d->m.r, (WIN_W / 2) + (d->m.r.w * 1.5), WIN_H / 2);
		mlx_put_image_to_window(d->mx, d->wptr, d->mlx.p, 0, 0);
	}
	if (d->c_char != 0 && d->is_main == 2)
		d->is_main = 0;
}

int	render(t_data *d)
{
	int	x;
	int	y;

	x = WIN_W / 2 - 200;
	y = WIN_H / 2 - 100;
	if (d->wptr == NULL)
		return (1);
	if (d->is_main > 0)
		render_main(d);
	else if (d->finished == 0)
	{
		render_background(d, WHITE_PIX);
		display_map(d);
		mlx_put_image_to_window(d->mx, d->wptr, d->mlx.p, 0, 0);
	}
	else
	{
		render_background(d, ORANGE_PIX);
		display_image(d, &d->win, x, y);
		mlx_put_image_to_window(d->mx, d->wptr, d->mlx.p, 0, 0);
	}
	return (0);
}
