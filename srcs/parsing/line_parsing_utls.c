/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing_utls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:01:58 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/17 19:03:57 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_f_color(char *line)
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(line, ',');
	if (!f)
		exit_str("Error\n");
	while (f[i])
		i++;
	if (i != 3)
		exit_str("Invalid color\n");
	free_loop(f);
}

void	check_c_color(char *line)
{
	int		i;
	char	**c;

	i = 0;
	c = ft_split(line, ',');
	if (!c)
		exit_str("Error\n");
	while (c[i])
		i++;
	if (i != 3)
		exit_str("Invalid color\n");
	free_loop(c);
}

void	check_lenght(char *line)
{
	check_f_color(line);
	check_c_color(line);
}
