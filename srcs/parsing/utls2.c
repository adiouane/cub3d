/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:38:12 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/09 01:35:14 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_NULL(t_map *map)
{
	if (map->no_name == NULL || map->so_name == NULL || map->we_name == NULL
		|| map->ea_name == NULL || map->f_name == NULL || map->c_name == NULL)
		error("Error: map invalid 3\n");
}

void	check_lenght(t_map *map)
{
	check_NULL(map);
	if (ft_strlen(map->no_name) != 2 || ft_strlen(map->so_name) != 2
		|| ft_strlen(map->we_name) != 2 || ft_strlen(map->ea_name) != 2
		|| ft_strlen(map->f_name) != 1 || ft_strlen(map->c_name) != 1)
		error("Error: map invalid 6\n");
}

void	save__name_no_so_we_ea_f_c(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] && i < map->position_wall)
	{
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "NO", 2) == 0)
			map->no_name = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "SO", 2) == 0)
			map->so_name = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "WE", 2) == 0)
			map->we_name = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "EA", 2) == 0)
			map->ea_name = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "F", 1) == 0)
			map->f_name = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "C", 1) == 0)
			map->c_name = ft_split(map->map[i], ' ')[0];
		i++;
	}
	check_NULL(map);
}

int	check_if_paths_are_deplicated(t_map *map, char *str)
{
	int	i;
	int	is_deplicated;

	is_deplicated = 0;
	i = 0;
	while (map->map[i])
	{
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], str, ft_strlen(str)) == 0)
			is_deplicated++;
		i++;
	}
	if (is_deplicated > 1)
		return (1);
	return (0);
}

void	check_deplicated(t_map *map)
{
	int	i;

	i = 0;
	check_NULL(map);
	while (map->map[i])
	{
		if (check_if_paths_are_deplicated(map, "NO")
			|| check_if_paths_are_deplicated(map, "SO")
			|| check_if_paths_are_deplicated(map, "WE")
			|| check_if_paths_are_deplicated(map, "EA")
			|| check_if_paths_are_deplicated(map, "F")
			|| check_if_paths_are_deplicated(map, "C"))
			error("Error: map invalid 4\n");
		i++;
	}
}
