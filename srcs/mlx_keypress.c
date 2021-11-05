/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keypress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:32 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:03:34 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keysym_main(t_data *data, int keysym)
{
	if (keysym == XK_Return && data->is_main < 2)
		data->is_main++;
	if (keysym == 49 && data->is_main == 2)
	{
		data->c_char = 1;
		choose_player(data);
	}
	if (keysym == 50 && data->is_main == 2)
	{
		data->c_char = 2;
		choose_player(data);
	}
	if (keysym == 51 && data->is_main == 2)
	{
		data->c_char = 3;
		choose_player(data);
	}
	if (keysym == 52 && data->is_main == 2)
	{
		data->c_char = 4;
		choose_player(data);
	}
}

void	keysym2(t_data *d)
{
	int	oldpos;

	oldpos = (int)d->px + (int)d->py;
	if (d->bm[(int)((d->px * d->rx) + d->bx)]
			[(int)(((d->py + 1 * d->mvsd) * d->ry) + d->by)] != '1'
	&& d->bm[(int)((d->px * d->rx) + d->dx)]
			[(int)(((d->py + 1 * d->mvsd) * d->ry) + d->dy)] != '1')
		d->py += 1 * d->mvsd;
	d->diry = 1;
	is_exitsprite(d);
	if ((oldpos != (int)d->px + (int)d->py) && d->finished == 0)
	{
		d->mvcount++;
		printf("%d\n", d->mvcount);
	}
}

void	keysym13(t_data *d)
{
	int	oldpos;

	oldpos = (int)d->px + (int)d->py;
	if (d->bm[(int)(((d->px - 1 * d->mvsd) * d->rx) + d->ax)]
			[(int)((d->py * d->ry) + d->ay)] != '1'
	&& d->bm[(int)(((d->px - 1 * d->mvsd) * d->rx) + d->bx)]
			[(int)((d->py * d->ry) + d->by)] != '1')
		d->px -= 1 * d->mvsd;
	is_exitsprite(d);
	if ((oldpos != (int)d->px + (int)d->py) && d->finished == 0)
	{
		d->mvcount++;
		printf("%d\n", d->mvcount);
	}
}

void	keysym0(t_data *d)
{
	int	oldpos;

	oldpos = (int)d->px + (int)d->py;
	if (d->bm[(int)((d->px * d->rx) + d->ax)]
			[(int)(((d->py - 1 * d->mvsd) * d->ry) + d->ay)] != '1'
	&& d->bm[(int)((d->px * d->rx) + d->cx)]
			[(int)(((d->py - 1 * d->mvsd) * d->ry) + d->cy)] != '1')
		d->py -= 1 * d->mvsd;
	d->diry = -1;
	is_exitsprite(d);
	if ((oldpos != (int)d->px + (int)d->py) && d->finished == 0)
	{
		d->mvcount++;
		printf("%d\n", d->mvcount);
	}
}

void	keysym1(t_data *d)
{
	int	oldpos;

	oldpos = (int)d->px + (int)d->py;
	if (d->bm[(int)(((d->px + 1 * d->mvsd) * d->rx) + d->cx)]
			[(int)((d->py * d->ry) + d->cy)] != '1'
	&& d->bm[(int)(((d->px + 1 * d->mvsd) * d->rx) + d->dx)]
			[(int)((d->py * d->ry) + d->dy)] != '1')
		d->px += 1 * d->mvsd;
	is_exitsprite(d);
	if ((oldpos != (int)d->px + (int)d->py) && d->finished == 0)
	{
		d->mvcount++;
		printf("%d\n", d->mvcount);
	}
}
