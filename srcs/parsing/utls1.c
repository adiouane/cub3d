/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:35:37 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 17:19:17 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// void	check_size(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (ft_strncmp(map[i], "1", 1) != 0
// 		|| ft_strncmp(map[i], " ", 1) != 0
// 		|| ft_strncmp(map[i], "\t", 1) != 0)
// 		{
// 			printf("%s\n", map[i]);
// 		i++;
// 		}
// 	if (i != 6)
// 		error("Error size is more then 6\n");
// }

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

void	save_map(t_map *map)
{
	int		i;
	int		j;

	i = 6;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strncmp(&map->map[i][j], "1", 1) == 0)
				map->matrix = &map->map[6];
			j++;
		}
		i++;
	}
}

void	save_map_dementions(t_map *map)
{
	int	i;

	i = 6;
	map->width = ft_strlen(map->map[6]);
	map->height = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) > map->width)
			map->width = ft_strlen(map->map[i]);
		map->height++;
		i++;
	}
}
