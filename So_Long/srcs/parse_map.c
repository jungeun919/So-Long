/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/18 16:25:47 by jungchoi         ###   ########.fr       */
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
	int	fd;
	int	row;

	fd = open(filename, O_RDONLY);
	row = 0;
	while (get_next_line(fd))
		row++;
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
	i = 0;
	str = ft_strdup("");
	while (i < row)
	{
		line = get_next_line(fd);
		if (line[0] == '\n')
			print_error("empty line in map.\n");
		temp = str;
		str = ft_strjoin(temp, line);
		free_ptr(&temp);
		free_ptr(&line);
		i++;
	}
	game->map.map = ft_split(str, '\n');
	if (!game->map.map)
		print_error_free("failed to split.\n", &(game->map));
	set_row_and_col(row, game);
	close(fd);
}

void	set_row_and_col(int row, t_game *game)
{
	game->map.row = row;
	game->map.col = (int)ft_strlen(game->map.map[0]);
}

/*
void	parse_map(t_game *game, char *filename)
{
	int	i;
	int	fd;
	int	row;

	row = get_map_row(filename);
	fd = open(filename, O_RDONLY);
	game->map.map = (char **)malloc(sizeof(char *) * row);
	if (!game->map.map)
		print_error("failed to malloc.\n", NULL);
	i = 0;
	while (i < row)
	{
		game->map.map[i] = get_next_line(fd);
		printf("%s", game->map.map[i]);
		if (game->map.map[i][0] == '\n')
			print_error("empty in line.\n", &(game->map));
		i++;
	}
	if (!(ft_strchr(game->map.map[row - 1], 10)))
		game->map.map[row - 1] = ft_strjoin(game->map.map[row - 1], "\n");
	game->map.row = row;
	game->map.col = (int)ft_strlen(game->map.map[0]);
	close(fd);
}
*/

/*
void	parse_map(t_game *game, int fd)
{
	char	*line;
	char	*str;
	char	*temp;

	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = str;
		str = ft_strjoin(temp, line);
		free(temp);
		free(line);
	}
	game->map.map = ft_split(str, '\n');
	if (!game->map.map[0])
		print_error("blank map.\n", &(game->map));
	if (ft_strnstr(str, "\n\n", ft_strlen(str)))
	{
		close(fd);
		print_error("empty line in map.\n", &(game->map));
	}
	close(fd);
	free(str);
}

void	parse_map(t_game *game, int fd)
{
	int		read_size;
	char	*buff;
	char	*str;
	char	*temp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	str = ft_strdup("");
	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			print_error("nothing to read.\n");
		buff[read_size] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
	}
	game->map.map = ft_split(str, '\n');
	free(buff);
	free(str);
}
*/
