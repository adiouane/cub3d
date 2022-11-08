/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:09:39 by adiouane          #+#    #+#             */
/*   Updated: 2022/11/08 01:27:13 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	if_something_missing(t_cub *cub)
{
	if (!cub->data->no || !cub->data->so || !cub->data->we || !cub->data->ea)
		exit_str("Missing texture");
	else if (cub->data->floor == -1 || cub->data->ceiling == -1)
		exit_str("Missing color");
	else if (!cub->data->map[0])
		exit_str("Missing map");
	else if (cub->player->x == -1 || cub->player->x == -1)
		exit_str("Missing player");
}

void	add_player(t_cub *cub, char **map, int y, int x)
{
	if (cub->player->x != -1 || cub->player->y != -1)
		exit_str("Duplicate player");
	cub->player->x = (x * TILE_SIZE) + 0.5;
	cub->player->y = (y * TILE_SIZE) + 0.5;
	if (map[y][x] == 'N')
		cub->player->angle = 270 * (M_PI / 180);
	else if (map[y][x] == 'S')
		cub->player->angle = 90 * (M_PI / 180);
	else if (map[y][x] == 'W')
		cub->player->angle = 180 * (M_PI / 180);
	else if (map[y][x] == 'E')
		cub->player->angle = 0 * (M_PI / 180);
	cub->data->map[y][x] = '0';
}

void	check_borders(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] == ' ') 
		j++;
	while(map[0][j] == '1')
		j++;
	if (map[0][j] != '1' && map[0][j] != '\0')
		exit_str("Error: map invalid\n");
}

void	checker(t_cub *cub, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (j > (int)ft_strlen(map[i + 1])
					|| j > (int)ft_strlen(map[i - 1]))
					exit_str("Error: map invalid");
				if (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
					|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
					|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
					|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
					exit_str("Error: map invalid");
			}
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				add_player(cub, map, i, j);
		}
	}
}

void	map_parsing(t_cub *cub, char *line, int fd)
{
	char	*tmp;

	while (line)
	{
		// if (!is_map(line)) // return 1 if line is a map 0 if not
		// 	exit_error("Invalid map", line);
		cub->data->height++;
		tmp = ft_strtrim(line, "\n");
		if (cub->data->width < (int)ft_strlen(tmp))
			cub->data->width = ft_strlen(tmp);
		cub->data->map = advanced_add(cub->data->map, tmp);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	free(line);
}
