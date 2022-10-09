/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:10:09 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/09 03:19:50 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_borders_first__last(t_map *map)
{
	int	j;

	j = 0;
	while (map->matrix[0][j] != '\0')
	{
		if (map->matrix[0][j] == '0')
			error("Error: wall invalid14\n");
		j++;
	}
	j = 0;
	while (map->matrix[map->height - 1][j])
	{
		if (map->matrix[map->height - 1][j] == '0')
			error("Error: wall invalid13\n");
		j++;
	}
}

void	check_borders(t_map *map)
{
	int	i;
	int	j;

	i = map->position_wall;
	while (map->matrix[i])
	{
		j = 0;
		while (ft_strncmp(&map->matrix[i][j], " ", 1) == 0)
			j++;
		if (map->matrix[i][j] != '1'
			|| map->matrix[i][ft_strlen(map->matrix[i]) - 1] != '1')
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
