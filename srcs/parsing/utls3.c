/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:54:31 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/08 17:35:11 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_f_color(t_map *map)
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(map->floor_color, ',');
	if (!f)
		error("Error\n");
	while (f[i])
		i++;
	if (i != 3)
		error("Invalid color\n");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(f[i]) > 255 || ft_atoi(f[i]) < 0)
			error("Invalid color\n");
		i++;
	}
	free(f);
}

void	check_c_color(t_map *map)
{
	int		i;
	char	**c;
	int		j;

	i = 0;
	j = 1;
	c = ft_split(map->ceiling_color, ',');
	if (!c)
		error("Error\n");
	while (c[i])
		i++;
	if (i != 3)
		error("Invalid color\n");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(c[i]) > 255 || ft_atoi(c[i]) < 0)
			error("Invalid color\n");
		i++;
	}
	free(c);
}

void	check_colors(t_map *map)
{
	check_f_color(map);
	check_c_color(map);
	printf("%s\n", map->floor_color);
	printf("%s\n", map->ceiling_color);
}
