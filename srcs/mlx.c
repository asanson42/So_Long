/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:23 by asanson           #+#    #+#             */
/*   Updated: 2021/10/29 17:11:50 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_data *data)
{
	ft_exit(data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if ((keysym == XK_Return || keysym == 49 || keysym == 50
			|| keysym == 51 || keysym == 52) && data->is_main > 0)
		keysym_main(data, keysym);
	if (keysym == XK_Escape)
		ft_exit(data);
	if (keysym == 100)
		keysym2(data);
	if (keysym == 119)
		keysym13(data);
	if (keysym == 97)
		keysym0(data);
	if (keysym == 115)
		keysym1(data);
	return (0);
}

int	mlx_network(t_data d)
{
	d.mx = mlx_init();
	if (d.mx == NULL)
		return (MLX_ERROR);
	d.wptr = mlx_new_window(d.mx, WIN_W, WIN_H, "SO_LONG");
	if (d.wptr == NULL)
	{
		free(d.wptr);
		return (MLX_ERROR);
	}
	if (get_texture(&d) == 0)
		return (0);
	get_all_ratio(&d);
	mlx_all_resize(&d);
	d.mlx.p = mlx_new_image(d.mx, WIN_W, WIN_H);
	d.mlx.ad = mlx_get_data_addr(d.mlx.p, &d.mlx.bp, &d.mlx.ln, &d.mlx.e);
	mlx_loop_hook(d.mx, &render, &d);
	mlx_hook(d.wptr, KeyPress, KeyPressMask, &handle_keypress, &d);
	mlx_hook(d.wptr, 33, 1L << 0, close_window, &d);
	mlx_loop(d.mx);
	return (0);
}
