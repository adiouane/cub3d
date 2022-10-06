/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:38:12 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/06 23:09:11 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_colors(t_map *map)
{
	int i = 0;
	char **F;

	F = ft_split(map->floor_color+1, ',');
	printf("%s\n", map->floor_color);
	while (F[i])
		i++;
	if (i != 3)
		error("Invalid color1\n");
	while (i < 3)
	{
		if (ft_atoi(F[i]) > 255 || ft_atoi(F[i]) < 0)
			error("Invalid color2\n");
		i++;
	}
	free(F);
	i = 0;
	char **C;
	C = ft_split(map->ceiling_color+1, ',');
	while (C[i])
		i++;
	if (i != 3)
		error("Invalid color3\n");
	while (i < 3)
	{
		if (ft_atoi(C[i]) > 255 || ft_atoi(C[i]) < 0)
			error("Invalid color4\n");
		i++;
	}
	free(C);
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

void	check_lenght(t_map *map)
{
	if (ft_strlen(map->NO) != 2 || ft_strlen(map->SO) != 2
		|| ft_strlen(map->WE) != 2 || ft_strlen(map->EA) != 2
		 || ft_strlen(map->F) != 1 || ft_strlen(map->C) != 1)
		error("Error 6\n");
}

void    save__name_SO_NO_EA_C_F(t_map *map)
{
    int i;

	i = 0;
    while(map->map[i] && i < map->position_wall)
    {
        if (ft_strncmp(ft_split(map->map[i], ' ')[0], "NO", 2) == 0)
            map->NO = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "SO", 2) == 0)
            map->SO = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "WE", 2) == 0)
            map->WE = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "EA", 2) == 0)
            map->EA = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "F", 1) == 0)
            map->F = ft_split(map->map[i], ' ')[0];
		if (ft_strncmp(ft_split(map->map[i], ' ')[0], "C", 1) == 0)
            map->C = ft_split(map->map[i], ' ')[0];
		printf("%s\n", map->map[i]);
        i++;
    }
    if (map->NO == NULL || map->SO == NULL || map->WE == NULL
		|| map->EA == NULL || map->F == NULL || map->C == NULL)
		error("Error PATH are NULL2\n");
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
	if (is_deplicated > 1)
		return (1);
	return (0);
}

void	check_deplicated(t_map *map)
{
    int i;
    
	if (map->NO == NULL || map->SO == NULL || map->WE == NULL
		|| map->EA == NULL || map->F == NULL || map->C == NULL)
		error("Error PATH are NULL 1\n");
    i = 0;
    while (map->map[i])
    {
        if (check_if_paths_are_deplicated(map, "NO") || check_if_paths_are_deplicated(map, "SO")
			|| check_if_paths_are_deplicated(map, "WE") || check_if_paths_are_deplicated(map, "EA")
			|| check_if_paths_are_deplicated(map, "F") || check_if_paths_are_deplicated(map, "C"))
			error("Error: is duplicated\n");
        i++;
    }
}
