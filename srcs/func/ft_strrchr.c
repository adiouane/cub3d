/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:59:43 by adiouane          #+#    #+#             */
/*   Updated: 2022/08/21 16:18:31 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char ) c)
			return ((char *) s + i);
	}
	return (NULL);
}
