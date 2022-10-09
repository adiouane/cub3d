/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:18:52 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/09 02:50:01 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>


void	check_exact_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strncmp(&map->map[i][j], "1111", 4) == 0)
			{
				map->position_wall = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_map(t_map *data)
{
	data->position_wall = 0;
	data->height = 0;
	data->width = 0;
	data->no_name = NULL;
	data->so_name = NULL;
	data->we_name = NULL;
	data->ea_name = NULL;
	data->c_name = NULL;
	data->f_name = 0;
	check_exact_line(data);
	data->matrix = &data->map[data->position_wall];
	save_maps_info(data);
	save_map_dementions(data);
	check(data);
	check_colors(data);
	langht_characters(data);
}
