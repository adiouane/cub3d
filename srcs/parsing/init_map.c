/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:22:15 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/07 02:18:36 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ckeck_paths_exists_with_open(t_map *map)
{
	int	fd;

	fd = open(map->no, O_RDONLY);
	if (fd == -1)
		exit_error("Error: no path", map->no);
	close(fd);
	fd = open(map->so, O_RDONLY);
	if (fd == -1)
		exit_error("Error: so path", map->so);
	close(fd);
	fd = open(map->we, O_RDONLY);
	if (fd == -1)
		exit_error("Error: we path", map->we);
	close(fd);
	fd = open(map->ea, O_RDONLY);
	if (fd == -1)
		exit_error("Error: ea path", map->ea);
	close(fd);
}

void	search_for_wall(char *buff, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (ft_strncmp(&buff[i], "11111", 5) == 0)
		{
			map->position_wall = i;
			break ;
		}
		i++;
	}
	j = map->position_wall;
	while (buff[j])
	{
		if ((buff[j] == '\n' && buff[j + 1] == '\n')
			|| (buff[j] == '\t' && buff[j + 1] == '\t'))
			error("Error tzb\n");
		j++;
	}
}

char	**ft_set_map(int fd, t_map *map)
{
	char	*stored;
	char	*buff;
	int		i;

	stored = ft_strdup("");
	if (fd < 0)
		error("Error fix 3your map\n");
	buff = malloc((4096 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = read(fd, buff, 4096);
	if (i == -1 || buff[i - 1] == '\n')
	{
		free(buff);
		error("error\n");
	}
	buff[i] = '\0';
	search_for_wall(buff, map);
	stored = ft_strjoine(stored, buff);
	free(buff);
	map->matrix = ft_split(stored, '\n');
	free(stored);
	if (!map->matrix)
		ft_exit();
	return (map->matrix);
}
