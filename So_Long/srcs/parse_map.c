/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/13 17:51:49 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("failed to open file.\n");
	return (fd);
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
