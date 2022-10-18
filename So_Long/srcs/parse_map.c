/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/18 19:09:45 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_file_and_check_extension(char *filename)
{
	int		fd;
	char	*extension;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("failed to open file.\n");
	extension = ft_strrchr(filename, '.');
	if (!extension)
		print_error("invalid filename.\n");
	if (ft_strncmp(extension, ".ber", 4))
		print_error("invalid file extension.\n");
	if (*(extension + 4))
		print_error("invalid file extension.\n");
	close(fd);
}

int	get_map_row(char *filename)
{
	int		fd;
	int		row;
	char	*line;

	fd = open(filename, O_RDONLY);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		row++;
		free(line);
	}
	close(fd);
	if (row == 0)
		print_error("blank map.\n");
	return (row);
}

void	parse_map(t_game *game, char *filename, int row)
{
	int		i;
	int		fd;
	char	*line;
	char	*str;
	char	*temp;

	fd = open(filename, O_RDONLY);
	i = -1;
	str = ft_strdup("");
	while (++i < row)
	{
		line = get_next_line(fd);
		if (line[0] == '\n')
			print_error("empty line in map.\n");
		temp = str;
		str = ft_strjoin(temp, line);
		free_ptr(&temp);
		free_ptr(&line);
	}
	game->map.map = ft_split(str, '\n');
	if (!game->map.map)
		print_error_free("failed to split.\n", &(game->map));
	free_ptr(&str);
	set_row_and_col(row, game);
	close(fd);
}

void	set_row_and_col(int row, t_game *game)
{
	game->map.row = row;
	game->map.col = (int)ft_strlen(game->map.map[0]);
}
