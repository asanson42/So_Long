/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:25 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:27 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_exit(t_data *data, char **nmap, int x, int y)
{
	new_exit1(data, nmap, x, y);
	new_exit2(data, nmap, x, y);
	new_exit3(data, nmap, x, y);
	new_exit4(data, nmap, x, y);
	new_exit5(data, nmap, x, y);
}

void	new_render(t_data *data, char **nmap, int x, int y)
{
	int		i;
	int		j;
	char	c;

	c = data->map.map[x][y];
	i = x * data->rx;
	while (i < x * data->rx + data->rx)
	{
		j = y * data->ry;
		while (j < y * data->ry + data->ry)
			nmap[i][j++] = c;
		i++;
	}
}

void	new_map1(t_map map, t_data *data, char **nmap)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.x)
	{
		j = 0;
		while (j < map.y)
		{
			if (data->map.map[i][j] == 'E')
				new_exit(data, nmap, i, j++);
			else
				new_render(data, nmap, i, j++);
		}
		i++;
	}
}

static void	free_bigmap(char **bm)
{
	int	i;

	i = 0;
	while (i < WIN_H)
		free(bm[i++]);
	free(bm);
	bm = NULL;
}

char	**new_map(t_map	map, t_data *data)
{
	char	**new_map;
	int		i;

	if (data->bm != NULL)
		free_bigmap(data->bm);
	new_map = malloc(sizeof(char *) * WIN_H + 1);
	if (!new_map)
		return (0);
	i = 0;
	while (i < WIN_H)
	{
		new_map[i] = malloc(sizeof(char) * WIN_W + 1);
		new_map[i][WIN_W] = '\0';
		i++;
	}
	new_map1(map, data, new_map);
	return (new_map);
}
