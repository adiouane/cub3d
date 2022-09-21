/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:15:59 by adiouane          #+#    #+#             */
/*   Updated: 2022/09/21 17:51:44 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>

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
		exit_error("invalid file extension", ext);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_strerr(str, errno);
	data->map = ft_set_map(fd);
	init_map(data);
	close(fd);
}