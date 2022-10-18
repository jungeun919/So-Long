/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:51:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/18 16:30:03 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	int		row;
	t_game	game;

	if (argc != 2)
		print_error("map file does not exist.\n");
	game.mlx = mlx_init();
	open_file_and_check_extension(argv[1]);
	row = get_map_row(argv[1]);
	parse_map(&game, argv[1], row);
	check_map(&game);
	set_image(&game);
	game.window = mlx_new_window(game.mlx, \
		game.map.col * PX, game.map.row * PX, "so_long");
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	print_map(&game);
	mlx_loop(game.mlx);
	system("leaks so_long");
	return (0);
}

int	click_destroy(t_game *game)
{
	free_map(&(game->map));
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	print_error(char *str)
{
	if (!str)
		ft_putstr_fd("Error\n", 2);
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
	}
	exit(0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
	map->map = NULL;
}

void	print_error_free(char *str, t_map *map)
{
	print_error(str);
	free_map(map);
	exit(0);
}
