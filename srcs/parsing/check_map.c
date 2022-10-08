/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:10:09 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/08 20:26:15 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_borders_first__last(t_map *map)
{
	int	j;

	j = 0;
	while (map->map[6][j] != '\0')
	{
		if (map->map[6][j] == '0')
			error("Error: wall invalid14\n");
		j++;
	}
	j = 0;
	while (map->map[map->height + 5][j] != '\0')
	{
		if (map->map[map->height + 5][j] == '0')
			error("Error: wall invalid13\n");
		j++;
	}
}

void	check_borders(t_map *map)
{
	int	i;
	int	j;

	i = 6;
	while (map->map[i])
	{
		j = 0;
		while (ft_strncmp(&map->map[i][j], " ", 1) == 0)
			j++;
		if (map->map[i][j] != '1'
			|| map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			error("Error: map invalid12\n");
		i++;
	}
	check_borders_first__last(map);
}

void	check_map(t_map *map)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (map->matrix[++i])
	{
		j = -1;
		while (map->matrix[i][++j])
		{
			if (map->matrix[i][j] == '0')
			{
				if (map->matrix[i][j - 1] == ' '
				|| map->matrix[i][j - 1] == '\0' || map->matrix[i][j + 1] == ' '
				|| map->matrix[i][j + 1] == '\0' || map->matrix[i - 1][j] == ' '
				|| map->matrix[i - 1][j] == '\0' || map->matrix[i + 1][j] == ' '
				|| map->matrix[i + 1][j] == '\0'
				|| j > ft_strlen(map->matrix[i + 1])
				|| j > ft_strlen(map->matrix[i - 1]))
					error("Error: map invalid11\n");
			}
		}
	}
}

void	check(t_map *map)
{
	check_borders(map);
	check_map(map);
	check_characters(map);
	save__name_no_so_we_ea_f_c(map);
	check_deplicated(map);
	check_lenght(map);
}
