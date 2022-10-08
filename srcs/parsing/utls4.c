/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:57:28 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/08 21:44:12 by adiouane         ###   ########.fr       */
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

void	langht_characters(t_map *map)
{
	int N;
	int S;
	int W;
	int E;

	N = 0;
	S = 0;
	W = 0;
	E = 0;
	while (map->map[6])
	{
		if (ft_strchr(map->map[6], 'N'))
			N++;
		if (ft_strchr(map->map[6], 'S'))
			S++;
		if (ft_strchr(map->map[6], 'W'))
			W++;
		if (ft_strchr(map->map[6], 'E'))
			E++;
		map->map++;
	}
	if (N > 1 || S > 1 || W > 1 || E > 1)
		error("Error: Invalid character\n");
}