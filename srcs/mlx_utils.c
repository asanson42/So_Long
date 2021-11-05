/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:47 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:03:49 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	mlx_resize_img(t_data *data, void *mlx, t_img img)
{
	t_img	new;
	int		i;
	int		j;
	int		x;
	int		y;

	new.p = mlx_new_image(mlx, img.w * img.rtexx, img.h * img.rtexy);
	new.ad = mlx_get_data_addr(new.p, &new.bp, &new.ln, &new.e);
	new.w = img.w * img.rtexy;
	new.h = img.h * img.rtexx;
	i = 0;
	while (i < new.h)
	{
		x = i / img.rtexx;
		j = 0;
		while (j < new.w)
		{
			y = j / img.rtexy;
			img_pixel_put(&new, j, i, get_pixel(&img, y, x));
			j++;
		}
		i++;
	}
	free_img(data, &img);
	return (new);
}

void	mlx_all_resize(t_data *data)
{
	data->r.p = mlx_resize_img(data, data->mx, data->r.p);
	data->r.m = mlx_resize_img(data, data->mx, data->r.m);
	data->r.l = mlx_resize_img(data, data->mx, data->r.l);
	data->r.s = mlx_resize_img(data, data->mx, data->r.s);
	data->b.p = mlx_resize_img(data, data->mx, data->b.p);
	data->b.m = mlx_resize_img(data, data->mx, data->b.m);
	data->b.l = mlx_resize_img(data, data->mx, data->b.l);
	data->b.s = mlx_resize_img(data, data->mx, data->b.s);
	data->g.p = mlx_resize_img(data, data->mx, data->g.p);
	data->g.m = mlx_resize_img(data, data->mx, data->g.m);
	data->g.l = mlx_resize_img(data, data->mx, data->g.l);
	data->g.s = mlx_resize_img(data, data->mx, data->g.s);
	data->y.p = mlx_resize_img(data, data->mx, data->y.p);
	data->y.m = mlx_resize_img(data, data->mx, data->y.m);
	data->y.l = mlx_resize_img(data, data->mx, data->y.l);
	data->y.s = mlx_resize_img(data, data->mx, data->y.s);
	data->f = mlx_resize_img(data, data->mx, data->f);
	data->w = mlx_resize_img(data, data->mx, data->w);
	data->e = mlx_resize_img(data, data->mx, data->e);
	data->x = mlx_resize_img(data, data->mx, data->x);
	data->s = mlx_resize_img(data, data->mx, data->s);
}
