/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:35 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:38 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_exit1(t_data *data, char **nmap, int x, int y)
{
	int	i;
	int	j;

	i = x * data->rx;
	while (i < x * data->rx + data->rx)
	{
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
			nmap[i][j++] = 'E';
		i++;
	}
}

void	new_exit2(t_data *data, char **nmap, int x, int y)
{
	int	i;
	int	j;

	i = x * data->rx;
	while (i < (x * data->rx) + (data->rx / 3))
	{
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
			nmap[i][j++] = '0';
		i++;
	}
}

void	new_exit3(t_data *data, char **nmap, int x, int y)
{
	int	i;
	int	j;

	i = x * data->rx + (data->rx / 3);
	while (i < x * data->rx + ((data->rx / 3) * 2))
	{
		j = y * data->ry;
		while (j < y * data->ry + (data->ry / 3))
			nmap[i][j++] = '0';
		i++;
	}
}

void	new_exit4(t_data *data, char **nmap, int x, int y)
{
	int	i;
	int	j;

	i = x * data->rx + ((data->rx / 3));
	while (i < x * data->rx + ((data->rx / 3) * 2))
	{
		j = y * data->ry + ((data->ry / 3) * 2);
		while (j < y * data->ry + data->ry)
			nmap[i][j++] = '0';
		i++;
	}
}

void	new_exit5(t_data *data, char **nmap, int x, int y)
{
	int	i;
	int	j;

	i = x * data->rx + ((data->rx / 3) * 2);
	{
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
			nmap[i][j++] = '0';
		i++;
	}
}
