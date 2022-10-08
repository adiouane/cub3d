/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:18:52 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/08 21:40:47 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_map(t_map *data)
{
	data->matrix = &data->map[6];
	save_maps_info(data);
	save_map_dementions(data);
	check(data);
	check_colors(data);
	langht_characters(data);
}
