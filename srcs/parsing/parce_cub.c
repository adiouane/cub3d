/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:15:59 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 19:41:29 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	parsing(char *str)
{
	int		fd;
	char	*ext;
	t_map	*data;

	data = malloc(sizeof(t_map));
	if (!data)
		return ;
	ext = ft_strrchr(str, '.');
	if (ft_strncmp(ext, ".cub\0", 5))
		error("Error\n");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error("Error\n");
	data->map = ft_set_map(fd, data);
	init_map(data);
	close(fd);
}
