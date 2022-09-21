/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:22:15 by adiouane          #+#    #+#             */
/*   Updated: 2022/09/21 20:19:55 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cub3D.h>
/* first we copy the map into a new array */
char	**ft_set_map(int fd)
{
	char	*stored;
	char	*buff;
	char	**matrix;
	int		i;

	stored = ft_strdup("");
	if (fd < 0)
		error("Error fix 3your map\n");
	buff = malloc((4096 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = read(fd, buff, 4096);
	// if (i == -1 || !i || buff[0] == '\n' || buff[i - 1] == '\n')
	// {
	// 	free(buff);
	// 	printf("error\n");
	// 	exit(0);
	// }
	buff[i] = '\0';
	stored = ft_strjoine(stored, buff);
	free(buff);
	matrix = ft_split(stored, '\n');
	free(stored);
	if (!matrix)
		ft_exit();
	// check_map(matrix, data);
	return (matrix);
}

void	check_size(char **map)
{
	int i = 0;
	while(ft_strncmp(map[i], "1", 1) != 0
		&& ft_strncmp(map[i], " ", 1) != 0 
		&& ft_strncmp(map[i], "\t", 1)!= 0)
		i++;
	if (i > 6)
		error("Error\n");
}


void	check_deplicated(t_map *map)
{
	if (check_if_paths_are_deplicated(map, "NO") > 1 || ft_strncmp(map->map[0], "NO ", 3) != 0)
		error("Error: NO is deplicated\n");
	if (check_if_paths_are_deplicated(map, "SO") > 1 || ft_strncmp(map->map[1], "SO ", 3) != 0)
		error("Error: SO is deplicated\n");
	if (check_if_paths_are_deplicated(map, "WE") > 1 || ft_strncmp(map->map[2], "WE ", 3) != 0)
		error("Error: WE is deplicated\n");
	if (check_if_paths_are_deplicated(map, "EA") > 1 || ft_strncmp(map->map[3], "EA ", 3) != 0)
		error("Error: EA is deplicated\n");
	if (check_if_paths_are_deplicated(map, "F") > 1 || ft_strncmp(map->map[4], "F ", 2) != 0)
		error("Error: F is deplicated\n");
	if (check_if_paths_are_deplicated(map, "C") > 1 || ft_strncmp(map->map[5], "C ", 2) != 0)
		error("Error: C is deplicated\n");
}

void	save_maps_info(t_map *map)
{
	int i;
	int j;
	
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strncmp(&map->map[i][j], "NO", 2) == 0)
				map->no = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "SO", 2) == 0)
				map->so = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "WE", 2) == 0)
				map->we = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "EA", 2) == 0)
				map->ea = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "F", 1) == 0)
				map->floor_color = ft_strdup(map->map[i]);
			if (ft_strncmp(&map->map[i][j], "C", 1) == 0)
				map->ceiling_color = ft_strdup(map->map[i]);
			j++;
		}
		i++;
	}
}

void	check_colors(t_map *map)
{
	int i = 0;
	char **F;

	F = ft_split(map->floor_color+1, ',');
	while (i < 3)
	{
		if (ft_atoi(F[i]) > 255 || ft_atoi(F[i]) < 0)
			error("Invalid color\n");
		i++;
	}
	free(F);
	i = 0;
	char **C;
	C = ft_split(map->ceiling_color+1, ',');
	while (i < 3)
	{
		if (ft_atoi(C[i]) > 255 || ft_atoi(C[i]) < 0)
			error("Invalid color\n");
		i++;
	}
	free(C);
}


void	save_map_dementions(t_map *map)
{
	map->width = ft_strlen(map->map[6]);
	map->height = 0;
	int i = 6;
	while(map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) > map->width)
			map->width = ft_strlen(map->map[i]);
		map->height++;
		i++;
	}
}

int		check_if_paths_are_deplicated(t_map *map, char *str)
{
	int i;
	int is_deplicated = 0;

	i = 0;
	while(map->map[i])
	{
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], str, ft_strlen(str)) == 0)
			is_deplicated++;
		i++;
	}
	return (is_deplicated);
}

int	is_character(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '1' || c == '0' || c == '\t')
		return (1);
	return (0);
}

void	check_characters(t_map *map)
{
	int i = 6;
	int j;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (!is_character(map->map[i][j]))
			{
				printf("character not found in line %d of map: '%c'\n", i, map->map[i][j]);
				error("Error: Invalid character\n");
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	check_borders(map);
	check_characters(map);
	int		i;
	int		j;

	i = 6;
	while (i < map->height + 5)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strncmp(&map->map[i][j], "0", 1) == 0)
			{
				if (ft_strncmp(&map->map[i][j - 1], " ", 1) == 0)
					printf("Error: Map has walls on the borders1 i =  %d, %s\n", i, map->map[i]);
				if (ft_strncmp(&map->map[i][j + 1], " ", 1) == 0)
					printf("Error: Map has walls on the borders2 i =  %d, %s\n", i, map->map[i]);
				if (ft_strncmp(&map->map[i - 1][j], " ", 1) == 0)
					printf("Error: Map has walls on the borders3 i =  %d, %s\n", i, map->map[i]);
				if (ft_strncmp(&map->map[i + 1][j], " ", 1) == 0)
					printf("Error: Map has walls on the borders4 i =  %d, %s\n", i, map->map[i]);
			}
			j++;
		}
		i++;
	}
}

void 	check_borders(t_map *map)
{
	int i;
	int j;

	i = 6;
	while(map->map[i])
	{
		// if (map->map[i] == '\n' ||map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
		// {
		// 	printf("error\n");
		// 	exit(0);
		// }
		j = 0;
		while (ft_strncmp(&map->map[i][j], " ", 1) == 0)
			j++;
		if (map->map[i][j] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
			error("Error: Map does not have walls on the borders\n");
		i++;
	}
	j = 0;
	while(map->map[6][j] != '\0')
	{
		if (map->map[6][j] == '0')
			error("Error: wall invalid\n");
		j++;
	}
	j = 0;
	while(map->map[map->height + 5][j] != '\0')
	{
		if (map->map[map->height + 5][j] == '0')
			error("Error: wall invalid\n");
		j++;
	}
}

void	save_map(t_map *map)
{
	int		i;
	int		j;

	i = 6;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strncmp(&map->map[i][j], "1", 1) == 0)
				map->matrix = &map->map[6];
			j++;
		}
		i++;
	}
	// i = 0;
	// while (map->matrix[i])
	// {
	// 	printf("map buffer= %s\n", map->matrix[i]);
	// 	i++;
	// }
}

void	ckeck_paths_exists_with_open(t_map *map)
{
	int fd;

	if ((fd = open(map->no, O_RDONLY)) == -1)
		exit_error("Error: no path", map->no);
	close(fd);
	if ((fd = open(map->so, O_RDONLY)) == -1)
		exit_error("Error: so path", map->so);
	close(fd);
	if ((fd = open(map->we, O_RDONLY)) == -1)
		exit_error("Error: we path", map->we);
	close(fd);
	if ((fd = open(map->ea, O_RDONLY)) == -1)
		exit_error("Error: ea path", map->ea);
	close(fd);
}

