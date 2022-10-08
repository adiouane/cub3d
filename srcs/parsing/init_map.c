/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:22:15 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/08 18:25:41 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
			error("Error: map invalid0\n");
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
		error("Error: map invalid1\n");
	buff = malloc((4096 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = read(fd, buff, 4096);
	if (i == -1 || buff[i - 1] == '\n' || buff[i - 1] == '\t')
	{
		free(buff);
		error("Error: map invalid2\n");
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
