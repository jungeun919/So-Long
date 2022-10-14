/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/14 13:13:41 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("failed to open file.\n", NULL);
	return (fd);
}

void	parse_map(t_game *game, int fd)
{
	size_t	len;
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
	len = ft_strlen(str);
	if (ft_strnstr(str, "\n\n", len))
	{
		close(fd);
		print_error("empty line in map.\n", &(game->map));
	}
	close(fd);
	free(str);
}

/*
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
