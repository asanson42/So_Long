/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:05:08 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 16:05:10 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_char(char c)
{
	if (c == '1' || c == '0' || c == 'c' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

int	error_map(char **map, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (map[i][j])
			if (!is_char(map[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

int	set_line(char *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		map[i] = line[i];
		i++;
	}
	map[i] = '\0';
	return (1);
}

int	get_all_sprites(char **map, t_map *info)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	info->sprite.x = malloc(sizeof(int *) * (info->sprite.sp));
	info->sprite.y = malloc(sizeof(int *) * (info->sprite.sp));
	while (i < info->x)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'c')
			{
				info->sprite.x[count] = i;
				info->sprite.y[count] = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	get_exit(char **map, t_map *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->x)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				info->set.exit++;
				info->e_x = i;
				info->e_y = j;
			}
			else if (map[i][j] == 'c')
				info->sprite.sp++;
			j++;
		}
		i++;
	}
	return (1);
}
