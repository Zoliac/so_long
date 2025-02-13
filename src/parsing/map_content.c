/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/11 21:43:59 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*fill_map(char *filame)
{
	char	**map;
	int		fd;

	map = NULL;
	fd = NULL;
	if (!filame)
		return ;
	fd = open(filame, O_RDONLY);
	while (get_next_line(fd) != '\0')
		map = get_next_line(fd);
	return (map);
}

int	map_check_rect(char **map)
{
	int	h;
	int	l;
	int	max_lgth;

	h = 0;
	max_lgth = 0;
	while (map[0][max_lgth])
		max_lgth++;
	while (map[h])
	{
		l = 0;
		while (map[h][l])
			l++;
		if (l != max_lgth)
		{
			perror("Map should be rectangular or square.");
			return (0);
		}
		h++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	h;
	int	l;
	int	max_h;
	int	max_l;

	if (!map || !map[0])
		return (perror("Invalid map."), 0);
	h = 0;
	l = 0;
	max_h = 0;
	max_l = 0;
	while (map[0][max_l])
		max_l++;
	while (map[max_h])
		max_h++;
	while (l < max_l && map[0][l] == '1' && map[max_h - 1][l] == '1')
		l++;
	if (l < max_l)
		return (perror("Map walls are invalid."), 0);
	while (h < max_h && map[h][0] == '1' && map[h][max_h - 1] == '1')
		h++;
	if (h < max_h)
		return (perror("Map walls are invalid."), 0);
	return (1);
}

int	map_check_valid(char **map)
{
	int	h;
	int	l;
	int	max_h;
	int	max_lgth;

	h = 0;
	l = 0;
	max_h = 0;
	max_lgth = 0;
	while (map[0][max_lgth])
		max_lgth++;
	while (map[max_h][0])
		max_h++;
	while (l < max_lgth || h < max_h)
	{
		if (map[h][l] != '0' || map[h][l] != '1' \
			|| map[h][l] != 'C' || map[h][l] != 'E' || map[h][l] != 'P')
		{
			perror("Map can't be played (There should only be 0, 1, C, E, P.)");
			return (0);
		}
		l += (l < max_lgth);
		h += (h < max_h);
	}
	return (1);
}

void	content_check(char *filame)
{
	char	**map;

	map = fill_map(filame);
	if (!map)
	{
		perror("Failed to load the map");
		return ;
	}
	if (!map_check_rect(map))
		return ;
	if (!check_walls(map))
		return ;
	if (!map_check_valid(map))
		return ;
}
