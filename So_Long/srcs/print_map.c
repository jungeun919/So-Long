/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:04:33 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/07 15:01:34 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_image(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->img.empty = mlx_xpm_file_to_image(game->mlx, \
		"images/empty.xpm", &width, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, \
		"images/wall.xpm", &width, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx, \
		"images/item.xpm", &width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"images/exit.xpm", &width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, \
		"images/player.xpm", &width, &height);
}

void	print_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			print_component(game, row, col);
			col++;
		}
		row++;
	}
}

void	print_component(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->window, \
			game->img.empty, col * PX, row * PX);
	if (game->map.map[row][col] == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->img.wall, col * PX, row * PX);
	else if (game->map.map[row][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->img.item, col * PX, row * PX);
	else if (game->map.map[row][col] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->img.exit, col * PX, row * PX);
	else if (game->map.map[row][col] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->img.player, col * PX, row * PX);
}
