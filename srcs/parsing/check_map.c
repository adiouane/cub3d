/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:10:09 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 00:45:03 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>

int	is_character(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '1' || c == '0' || c == '\t')
		return (1);
	return (0);
}

void	check_characters(t_map *map)
{
	int i = 6;
	int j;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (!is_character(map->map[i][j]))
			{
				printf("character not found in line %d of map: '%c'\n", i, map->map[i][j]);
				error("Error: Invalid character\n");
			}
			j++;
		}
		i++;
	}
}

void 	check_borders(t_map *map)
{
	int i;
	int j;

	i = 6;
	while(map->map[i])
	{
		j = 0;
		while (ft_strncmp(&map->map[i][j], " ", 1) == 0)
			j++;
		if (map->map[i][j] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			error("Error: Map does not have walls on the borders\n");
		i++;
	}
	j = 0;
	while(map->map[6][j] != '\0')
	{
		if (map->map[6][j] == '0')
			error("Error: wall invalid\n");
		j++;
	}
	j = 0;
	while(map->map[map->height + 5][j] != '\0')
	{
		if (map->map[map->height + 5][j] == '0')
			error("Error: wall invalid\n");
		j++;
	}
}

void	check_map(t_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (ft_strncmp(&map->matrix[i][j], "0", 1) == 0)
			{
				if (ft_strncmp(&map->matrix[i][j - 1], " ", 1) == 0)
					error("error: map invalid\n");
				if (ft_strncmp(&map->matrix[i][j + 1], " ", 1) == 0)
					error("error: map invalid\n");
				if (ft_strncmp(&map->matrix[i - 1][j], " ", 1) == 0)
					error("error: map invalid\n");
				if (ft_strncmp(&map->matrix[i + 1][j], " ", 1) == 0)
					error("error: map invalid\n");
				if ( j > ft_strlen(map->matrix[i + 1])
					|| j > ft_strlen(map->matrix[i - 1]))
				{
					printf("%s\n", map->matrix[i]);
					error("error: map invalid\n");
				}
			}
			j++;
		}
		i++;
	}
}

void check(t_map *map)
{
    check_borders(map);
	check_characters(map);
    check_map(map);	
	save__name_SO_NO_EA_C_F(map);
    check_deplicated(map);
	check_lenght(map);
}
