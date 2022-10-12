/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:25:33 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/12 16:33:03 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_game *game)
{
	check_rectangular_and_size(&(game->map));
	check_wall(&(game->map));
	check_component(game);
}

void	check_rectangular_and_size(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = ft_strlen(map->map[0]);
	while (map->map[row])
	{
		if ((int)ft_strlen(map->map[row]) != col)
			print_error("different from the shape of a rectangle.\n");
		row++;
	}
	map->row = row;
	map->col = col;
	if (map->col > 40 || map->row > 22)
		print_error("map size exceed max size of window.\n");
}

void	check_wall(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->row)
	{
		if (map->map[row][0] != '1' || map->map[row][map->col - 1] != '1')
			print_error("map does not surrounded by walls.\n");
		row++;
	}
	col = 0;
	while (col < map->col)
	{
		if (map->map[0][col] != '1' || map->map[map->row - 1][col] != '1')
			print_error("map does not surrounded by walls.\n");
		col++;
	}
}

void	check_component(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->map.row)
	{
		col = -1;
		while (++col < game->map.col)
		{
			if (game->map.map[row][col] == 'C')
				game->map.item++;
			else if (game->map.map[row][col] == 'E')
				game->map.exit++;
			else if (game->map.map[row][col] == 'P')
			{
				game->position.y = row;
				game->position.x = col;
				game->map.player++;
			}
			else if (game->map.map[row][col] != '0' \
				&& game->map.map[row][col] != '1')
				print_error("invalid components in map.\n");
		}
	}
	check_component_count(game);
}

void	check_component_count(t_game *game)
{
	if (game->map.exit != 1)
		print_error("game must have one exit.\n");
	else if (game->map.item < 1)
		print_error("game must have more than one item.\n");
	else if (game->map.player != 1)
		print_error("game must have one player.\n");
}
