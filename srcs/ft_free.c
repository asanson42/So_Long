/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:02:09 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:58:27 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_data *data, t_img *img)
{
	if (img->p != NULL)
	{
		mlx_destroy_image(data->mx, img->p);
		img->p = NULL;
	}
	else
		return ;
}

static void	ft_destroy(t_data *data)
{
	if (data->wptr != NULL)
	{
		mlx_destroy_window(data->mx, data->wptr);
		data->wptr = NULL;
	}
	if (data->mlx.p != NULL)
		mlx_destroy_image(data->mx, data->mlx.p);
	if (data->mx != NULL)
	{
		mlx_destroy_display(data->mx);
		free(data->mx);
	}
}

static void	free_all_img1(t_data *data)
{
	free_img(data, &data->r.p);
	free_img(data, &data->r.m);
	free_img(data, &data->r.l);
	free_img(data, &data->r.s);
	free_img(data, &data->b.p);
	free_img(data, &data->b.m);
	free_img(data, &data->b.l);
	free_img(data, &data->b.s);
	free_img(data, &data->g.p);
	free_img(data, &data->g.m);
	free_img(data, &data->g.l);
	free_img(data, &data->g.s);
	free_img(data, &data->y.p);
	free_img(data, &data->y.m);
	free_img(data, &data->y.l);
	free_img(data, &data->y.s);
}

static void	free_all_img2(t_data *data)
{
	free_img(data, &data->w);
	free_img(data, &data->f);
	free_img(data, &data->s);
	free_img(data, &data->e);
	free_img(data, &data->x);
	free_img(data, &data->win);
	free_img(data, &data->m.b);
	free_img(data, &data->m.r);
	free_img(data, &data->m.g);
	free_img(data, &data->m.y);
	free_img(data, &data->m.t);
	free_img(data, &data->m.s);
}

void	ft_exit(t_data *data)
{
	int	i;

	free_all_img1(data);
	free_all_img2(data);
	ft_destroy(data);
	i = 0;
	while (i < WIN_H)
		free(data->bm[i++]);
	free(data->bm);
	data->bm = NULL;
	i = 0;
	while (i <= data->map.x)
		free(data->map.map[i++]);
	free(data->map.map);
	data->map.map = NULL;
	free(data->map.sprite.x);
	free(data->map.sprite.y);
	exit(0);
}
