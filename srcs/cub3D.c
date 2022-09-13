/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:31 by omanar            #+#    #+#             */
/*   Updated: 2022/08/25 19:31:02 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_character(char *map)
{
	if (map[0] == 'N' || map[0] == 'S' || map[0] == 'W' || map[0] == 'E')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./cub3D <filename.cub>\n");
		return (0);
	}
	parsing(av[1]);
	return (0);
}
