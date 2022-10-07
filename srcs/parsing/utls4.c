/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:57:28 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 02:26:52 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_character(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '1' || c == '0' || c == '\t')
		return (1);
	return (0);
}

void	check_characters(t_map *map)
{
	int	i;
	int	j;

	i = 6;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_character(map->map[i][j]))
				error("Error: Invalid character\n");
			j++;
		}
		i++;
	}
}
