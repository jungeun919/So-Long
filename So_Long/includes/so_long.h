/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:44:46 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/14 13:13:11 by jungchoi         ###   ########.fr       */
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

# define ON_CLICK 2
# define ON_DESTROY 17

# define PX 64
# define BUFFER_SIZE 10
# define OPEN_MAX 256

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
}	t_position;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_map		map;
	t_position	position;
	int			step;
}	t_game;

int		click_destroy(t_game *game);
void	print_error(char *str, t_map *map);
void	free_map(t_map *map);

int		open_file_and_check_extension(char *filename);
void	parse_map(t_game *game, int fd);

void	check_map(t_game *game);
void	check_rectangular_and_size(t_map *map);
void	check_wall(t_map *map);
void	check_component(t_game *game);
void	check_component_count(t_game *game);

void	set_image(t_game *game);
void	print_map(t_game *game);
void	print_component(t_game *game, int row, int col);

int		press_key(int keycode, t_game *game);
void	check_movable(t_game *game, t_position *next);
void	print_step_and_update_map(t_game *game, t_position *next);

// gnl
void	free_ptr(char **ptr);
char	*ret_line(char **backup);
char	*cut_backup(char **backup);
char	*read_buff(int fd, char **backup);
char	*get_next_line(int fd);

#endif
