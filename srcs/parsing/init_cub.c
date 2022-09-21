/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:18:52 by adiouane          #+#    #+#             */
/*   Updated: 2022/09/21 20:12:12 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>

void    init_map(t_map *data)
{
    check_size(data->map);
	save_maps_info(data);
	check_colors(data);
	save_map_dementions(data);
	// ckeck_paths_exists_with_open(&data);
	check_map(data);
	check_deplicated(data);
	save_map(data);
}
