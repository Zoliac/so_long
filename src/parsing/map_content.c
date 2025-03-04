/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 18:28:43 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**fill_map(char *filename, t_game *game)
{
	int		fd;
	char	*lines;
	char	**map;
	int		i;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	map = NULL;
	while (1)
	{
		lines = get_next_line(fd);
		if (lines)
			break ;
		lines[ft_strlen(lines) - 1] = '\0';
		map = add_line_map(map, &i, lines);
	}
	close(fd);
	map = realloc_map(map, i + 1);
	game->map = map;
	return (game->map);
}

int	map_check_rect(t_game *game)
{
	int	h;
	int	l;

	h = 0;
	while (game->map[h])
	{
		l = 0;
		while (game->map[h][l])
			l++;
		if (l != game->map_width)
		{
			perror("Map should be rectangular or square.");
			return (0);
		}
		h++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	h;
	int	l;

	if (!game->map || !game->map[0])
		return (perror("Invalid map."), 0);
	h = 0;
	l = 0;
	while (l < game->map_width && game->map[0][l] == '1' && game->map[game->map_height - 1][l] == '1')
		l++;
	if (l < game->map_width)
		return (perror("Map walls are invalid."), 0);
	while (h < game->map_height && game->map[h][0] == '1' && game->map[h][game->map_height - 1] == '1')
		h++;
	if (h < game->map_height)
		return (perror("Map walls are invalid."), 0);
	return (1);
}

int	map_check_valid(t_game *game)
{
	int	h;
	int	l;
	
	h = 0;
	l = 0;
	while (l < game->map_width || h < game->map_height)
	{
		if (game->map[h][l] != '0' || game->map[h][l] != '1' \
			|| game->map[h][l] != 'C' || game->map[h][l] != 'E' || game->map[h][l] != 'P')
		{
			perror("Map can't be played (There should only be 0, 1, C, E, P.)");
			return (0);
		}
		l += (l < game->map_width );
		h += (h < game->map_height);
	}
	return (1);
}

void	content_check(t_game *game)
{
	if (!map_check_rect(game))
		return ;
	if (!check_walls(game))
		return ;
	if (!map_check_valid(game))
		return ;
}
