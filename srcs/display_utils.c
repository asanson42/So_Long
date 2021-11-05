/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:01:55 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:01:58 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pixel(t_img *img, long int x, long int y)
{
	long int	index;
	int			color;

	index = y * img->ln + x * (img->bp / 8);
	ft_memcpy(&color, &img->ad[index], 4);
	return (color);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->ad + (y * img->ln + x * (img->bp / 8));
	*(int *)pixel = color;
}

void	display_player(t_data *data, double x, double y)
{
	if (((int)data->px + (int)data->py) % 2 == 0)
	{
		if (data->diry > 0)
			render_player(data, data->play, x, y);
		else
			render_player(data, data->left, x, y);
	}
	else
	{
		if (data->diry > 0)
			render_player(data, data->move, x, y);
		else
			render_player(data, data->mleft, x, y);
	}
}

void	display_sprites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.x)
	{
		j = 0;
		while (j < data->map.y)
		{
			if (data->map.map[i][j] == 'c')
				render_sp(data, i, j);
			j++;
		}
		i++;
	}
}

void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.x)
	{
		j = 0;
		while (j < data->map.y)
			render_rect(data, i, j++);
		i++;
	}
	display_sprites(data);
	display_player(data, data->px, data->py);
}
