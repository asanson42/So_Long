/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:55 by asanson           #+#    #+#             */
/*   Updated: 2021/10/29 16:57:58 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(int fd, t_map *map)
{
	char	*arg;
	int		ret;
	int		i;
	int		len;

	arg = NULL;
	len = 0;
	i = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &arg);
		if (ret == 1)
		{
			if (ft_strlen(arg) > len)
				len = ft_strlen(arg);
			i++;
		}
		free(arg);
	}
	if (i == 0)
		return (0);
	map->x = i;
	map->y = len;
	return (1);
}

int	set_map(int fd, t_map *map)
{
	int		ret;
	int		i;
	int		j;
	char	*line;

	line = NULL;
	i = 0;
	j = 0;
	ret = 1;
	map->map = malloc(sizeof(char *) * (map->x + 1));
	while (i <= map->x)
	{
		map->map[i] = malloc(sizeof(char) * (map->y + 1));
		map->map[i][map->y] = '\0';
		i++;
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		set_line(map->map[j++], line);
		free(line);
	}
	return (1);
}

int	manag_map(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (get_map(fd, map) == 0)
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	set_map(fd, map);
	close(fd);
	if (error_map(map->map, map->x) == 0)
		return (0);
	if (verif_map(map->map, map->x - 1, map->y - 1) == 0)
		return (0);
	get_exit(map->map, map);
	get_player(map->map, map);
	if (map->set.player != 1 || map->set.exit != 1)
		return (0);
	get_all_sprites(map->map, map);
	if (map->sprite.sp <= 0)
		return (0);
	return (1);
}
