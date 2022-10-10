/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/07 15:14:04 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_game *game, char *filename)
{
	int		fd;
	int		read_size;
	char	*buff;
	char	*str;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("failed to open file.\n");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = ft_strdup("");
	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[read_size] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
	}
	game->map.map = ft_split(str, '\n');
	free(buff);
	free(str);
}

void	check_map(t_game *game)
{
	check_rectangular_and_size(&(game->map));
	check_wall(&(game->map));
	check_component(&(game->map));
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

void	check_component(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < map->row)
	{
		while (col < map->col)
		{
			if (map->map[row][col] == 'C')
				map->item++;
			else if (map->map[row][col] == 'E')
				map->exit++;
			else if (map->map[row][col] == 'P')
			{
				map->player++;
				continue ;
			}
			else if (map->map[row][col] != '0' && map->map[row][col] != '1')
				print_error("invalid components in map.\n");
			col++;
		}
		row++;
	}
}
