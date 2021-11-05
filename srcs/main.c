/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:03:08 by asanson           #+#    #+#             */
/*   Updated: 2021/10/25 17:29:23 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->map)
		return ;
	while (i <= map->x)
		free(map->map[i++]);
	free(map->map);
	map->map = NULL;
	free(map->sprite.x);
	free(map->sprite.y);
}

static int	ft_check_file(char *file)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(file);
	while (!(len - i == 4))
		i++;
	if (ft_strcmp((file + i), ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	data = init_all_data();
	if (ft_check_file(argv[1]) == 0)
	{
		printf("Error: invalid file.\n");
		return (0);
	}
	if (manag_map(argv[1], &data.map) == 0)
	{
		free_map(&data.map);
		printf("Invalid map or file.\n");
		return (0);
	}
	data.rx = WIN_H / data.map.x;
	data.ry = WIN_W / data.map.y;
	data.px = data.map.p_x;
	data.py = data.map.p_y;
	data.mvsd = 0.16;
	data.bm = new_map(data.map, &data);
	data.num_sprites = data.map.sprite.sp;
	mlx_network(data);
	return (0);
}
