/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:35:37 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/09 02:24:28 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	save_maps_info(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strncmp(&map->map[i][j], "NO", 2) == 0)
				map->no = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "SO", 2) == 0)
				map->so = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "WE", 2) == 0)
				map->we = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "EA", 2) == 0)
				map->ea = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "F", 1) == 0)
				map->floor_color = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "C", 1) == 0)
				map->ceiling_color = ft_strdup(map->map[i]);
			j++;
		}
		i++;
	}
}

void	save_map_dementions(t_map *map)
{
	int	i;

	i = map->position_wall;
	map->width = ft_strlen(map->map[map->position_wall]);
	map->height = map->position_wall;
	while (map->matrix[i])
	{
		if ((int)ft_strlen(map->matrix[i]) > map->width)
			map->width = ft_strlen(map->matrix[i]);
		map->height++;
		i++;
	}
}
