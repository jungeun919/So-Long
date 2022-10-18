/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:13:39 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/18 19:10:12 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int keycode, t_game *game)
{
	t_position	next;

	next = game->position;
	if (keycode == KEY_W)
		next.y = game->position.y - 1;
	else if (keycode == KEY_A)
		next.x = game->position.x - 1;
	else if (keycode == KEY_S)
		next.y = game->position.y + 1;
	else if (keycode == KEY_D)
		next.x = game->position.x + 1;
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
	check_movable(game, &next);
	return (0);
}

void	check_movable(t_game *game, t_position *next)
{
	if (game->map.map[next->y][next->x] == '1')
		return ;
	else if (game->map.map[next->y][next->x] == '0')
		print_step_and_update_map(game, next);
	else if (game->map.map[next->y][next->x] == 'C')
	{
		game->map.item--;
		print_step_and_update_map(game, next);
	}
	else if (game->map.map[next->y][next->x] == 'E' && game->map.item == 0)
	{
		print_step_and_update_map(game, next);
		mlx_destroy_window(game->mlx, game->window);
		exit(0);
	}
}

void	print_step_and_update_map(t_game *game, t_position *next)
{
	game->step++;
	printf("steps : %d\n", game->step);
	game->map.map[game->position.y][game->position.x] = '0';
	game->map.map[next->y][next->x] = 'P';
	game->position.x = next->x;
	game->position.y = next->y;
	print_map(game);
}
