/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:56:55 by adiouane          #+#    #+#             */
/*   Updated: 2022/10/09 03:35:28 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	error(char *errormsg)
{
	ft_putstr_fd(errormsg, 1);
	exit(0);
}

void	ft_exit(void)
{
	write(1, "Error\n", 7);
	write(1, "Fix your map !\n", 15);
	exit(0);
}
