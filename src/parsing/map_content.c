/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/11 16:53:32 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*fill_map(char *filename)
{
	char **map;
	int fd;

	map = NULL;
	fd = NULL;
	if (!filename)
		return ;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd) != '\0')
		map = get_next_line(fd);
	return (map);
}

void	map_check_len(char **map)
{
	
}

void	check_walls(char **map)
{
	int	height;
	int	length;
	int max_height;
	int max_length;

	height = 0;
	length = 0;
	max_height = 0;
	max_length = 0;
	while (map[1][max_length])
		max_length++;
	while (map[max_height][0])
		max_height++;
	while (length < max_length || height < max_height)
	{
		if (length < max_length && (map[0][length] != '0' \
					|| map[max_height - 1][length] != '0'))
			perror("Map is invalid.");
		if (height < max_height && (map[height][0] != '0' \
					|| map[height][max_length - 1] != '0'))
			perror("Map is invalid.");
		length += (length < max_length);
		height += (height < max_height);
	}
}

void	content_check(char *filename)
{
	char **map;

	map = fill_map(filename);
	check_walls(map);
	
}
