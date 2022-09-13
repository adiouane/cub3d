/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:21:38 by adiouane          #+#    #+#             */
/*   Updated: 2022/08/21 15:50:16 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*ft_strjoine(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	int		len1;
	char	*string;

	i = -1;
	j = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	len1 = ft_strlen(s2);
	string = (char *)malloc((len + len1 + 1) * sizeof(char));
	if (string == NULL)
		return (0);
	while (s1[++i])
		string[i] = s1[i];
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	return (string);
}
