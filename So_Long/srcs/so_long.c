/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:51:05 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/12 16:45:36 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		print_error("map file does not exist.\n");
	game.mlx = mlx_init();
	parse_map(&game, argv[1]);
	check_map(&game);
	set_image(&game);
	game.window = mlx_new_window(game.mlx, \
		game.map.col * PX , game.map.row * PX, "so_long");
	mlx_hook(game.window, ON_CLICK, 0, press_key, &game);
	mlx_hook(game.window, ON_DESTROY, 0, click_destroy, &game);
	print_map(&game);
	mlx_loop(game.mlx);
	return (0);
}

int	click_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}
