/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:54:31 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 02:26:30 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_f_color(t_map *map)
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(map->floor_color, ',');
	while (f[i])
		i++;
	if (i != 3)
		error("Invalid color1\n");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(f[i]) > 255 || ft_atoi(f[i]) < 0)
			error("Invalid color2\n");
		i++;
	}
	free(f);
}

void	check_c_color(t_map *map)
{
	int		i;
	char	**c;

	i = 0;
	c = ft_split(map->ceiling_color, ',');
	while (c[i])
		i++;
	if (i != 3)
		error("Invalid color3\n");
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(c[i]) > 255 || ft_atoi(c[i]) < 0)
			error("Invalid color4\n");
		i++;
	}
	free(c);
}

void	check_colors(t_map *map)
{
	check_f_color(map);
	check_c_color(map);
}
