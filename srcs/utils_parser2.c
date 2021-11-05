/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:04:59 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:05:01 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player(char **map, t_map *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->x)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				info->set.player++;
				info->p_x = i;
				info->p_y = j;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_map(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
		if (map[0][j++] != '1')
			return (0);
	while (i < x)
	{
		if (map[i][0] != '1' || map[i][y] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[x][j])
		if (map[x][j++] != '1')
			return (0);
	return (1);
}
