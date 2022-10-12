/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:51:14 by jungchoi          #+#    #+#             */
/*   Updated: 2022/10/12 16:26:07 by jungchoi         ###   ########.fr       */
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
