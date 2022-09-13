/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:11:08 by omanar            #+#    #+#             */
/*   Updated: 2022/09/13 02:10:45 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53
# define RIGHT 5555
# define LEFT 5556

typedef struct map {
	char		**map;
	char		**matrix;
	int			width;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*floor_color;
	char		*ceiling_color;
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
}	t_map;

/*----------------------------------PARSING------------------------------------------*/
void	parsing(char *str);

/*----------------------------------ERRORS------------------------------------------*/
void	exit_strerr(char *str, int err);
void	exit_error(char *str, char *err);
void	error(char *errormsg);
void	ft_exit(void);
/*----------------------------------INIT------------------------------------------*/
void    init_map(t_map *data);
void    init_mlx(t_map *data);
/*----------------------------------DRAW------------------------------------------*/
void	draw_map(t_map	*data);
/*----------------------------------HELPER------------------------------------------*/
char	*ft_strjoine(char *s1, char const *s2);
/*----------------------------------MLX------------------------------------------*/
void	init_window(t_map *data);
/*----------------------------------PIXEL------------------------------------------*/

/*----------------------------------MAP------------------------------------------*/
void	save_maps_info(t_map *map);
char	**ft_set_map(int fd);
void	check_size(char **map);
void	check_deplicated(t_map *map);
void	save_maps_info(t_map *map);
void	check_colors(t_map *map);
void	save_map_dementions(t_map *map);
int		check_if_paths_are_deplicated(t_map *map, char *str);
void	check_map(t_map *map);
void 	check_borders(t_map *map);
void	save_map(t_map *map);
void	ckeck_paths_exists_with_open(t_map *map);

/*----------------------------------PLAYER_MOVE------------------------------------------*/

/*----------------------------------RAYCASTING------------------------------------------*/

#endif