/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:46 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/07 15:08:37 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define PX 64
# define BUFFER_SIZE 10

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*item;
	void	*exit;
	void	*player;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
	int		item;
	int		exit;
	int		player;
}	t_map;

typedef struct s_position
{
	int	x;
	int	y;
	int	step;
}	t_position;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_map		map;
	t_position	position;
}	t_game;

void	print_error(char *str);

void	parse_map(t_game *game, char *filename);
void	check_map(t_game *game);
void	check_rectangular_and_size(t_map *map);
void	check_wall(t_map *map);
void	check_component(t_map *map);

void	set_image(t_game *game);
void	print_map(t_game *game);
void	print_component(t_game *game, int row, int col);

#endif
