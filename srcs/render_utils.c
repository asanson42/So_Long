/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:15 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:18 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
			img_pixel_put(&data->mlx, j++, i, color);
		++i;
	}
}

int	get_jcolor(t_data *data, char c, int sx, int sy)
{
	int	color;

	if (c == '1')
		color = get_pixel(&data->w, sy, sx);
	else if (c == 'P' || c == 'c' || c == '0')
		color = get_pixel(&data->f, sy, sx);
	else if (c == 'E')
	{
		if (data->exit == 0)
			color = get_pixel(&data->e, sy, sx);
		else if (data->exit == 1)
			color = get_pixel(&data->x, sy, sx);
		if (color <= 0)
			color = get_pixel(&data->f, sy, sx);
	}
	return (color);
}

void	render_rect(t_data *data, int x, int y)
{
	double	i;
	double	j;
	int		sx;
	int		sy;
	int		color;

	i = x * data->rx;
	sx = 0;
	while (i < x * data->rx + data->rx)
	{
		sy = 0;
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
		{
			color = get_jcolor(data, data->map.map[x][y], sx, sy);
			img_pixel_put(&data->mlx, j, i, color);
			j++;
			sy++;
		}
		sx++;
		i++;
	}
}

void	render_sp(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;
	int	sx;
	int	sy;

	i = x * data->rx;
	sx = 0;
	while (i < x * data->rx + data->rx - (data->rx / 3))
	{
		sy = 0;
		j = y * data->ry;
		while (j < y * data->ry + data->ry - (data->ry / 3))
		{
			color = get_pixel(&data->s, sy, sx);
			if (color <= 0)
				color = get_pixel(&data->f, sy, sx);
			img_pixel_put(&data->mlx, j, i, color);
			j++;
			sy++;
		}
		sx++;
		i++;
	}
}

void	render_player(t_data *data, t_img img, double x, double y)
{
	int		i;
	int		j;
	int		color;
	int		sx;
	int		sy;

	i = x * data->rx;
	sx = 0;
	while (i < x * data->rx + data->rx)
	{
		sy = 0;
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
		{
			color = get_pixel(&img, sy, sx);
			if (color <= 0)
				color = get_pixel(&data->mlx, j, i);
			img_pixel_put(&data->mlx, j, i, color);
			j++;
			sy++;
		}
		sx++;
		i++;
	}
}
