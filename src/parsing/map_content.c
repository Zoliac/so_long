/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/21 14:14:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*fill_map(char *filame, t_game *game)
{
	int		fd;
	
	fd = NULL;
	if (!filame)
		return ;
	fd = open(filame, O_RDONLY);
	while (get_next_line(fd) != '\0')
		game->map = get_next_line(fd);
	return (game->map);
}

int	map_check_rect(t_game *game)
{
	int	h;
	int	l;
	int	max_lgth;

	h = 0;
	max_lgth = max_length(map);
	while (game->map[h])
	{
		l = 0;
		while (game->map[h][l])
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

int	check_walls(t_game *game)
{
	int	h;
	int	l;
	int	max_h;
	int	max_l;

	if (!game->map || !game->map[0])
		return (perror("Invalid map."), 0);
	h = 0;
	l = 0;
	max_h = max_height(game);
	max_l = max_width(game);
	while (l < max_l && game->map[0][l] == '1' && game->map[max_h - 1][l] == '1')
		l++;
	if (l < max_l)
		return (perror("Map walls are invalid."), 0);
	while (h < max_h && game->map[h][0] == '1' && game->map[h][max_h - 1] == '1')
		h++;
	if (h < max_h)
		return (perror("Map walls are invalid."), 0);
	return (1);
}

int	map_check_valid(t_game *game)
{
	int	h;
	int	l;
	int	max_h;
	int	max_lgth;

	h = 0;
	l = 0;
	max_h = max_height(game);
	max_lgth = max_width(game);
	while (l < max_lgth || h < max_h)
	{
		if (game->map[h][l] != '0' || game->map[h][l] != '1' \
			|| game->map[h][l] != 'C' || game->map[h][l] != 'E' || game->map[h][l] != 'P')
		{
			perror("Map can't be played (There should only be 0, 1, C, E, P.)");
			return (0);
		}
		l += (l < max_lgth);
		h += (h < max_h);
	}
	return (1);
}

void	content_check(char *filame, t_game *game)
{
	fill_map(filame, game);
	if (!fill_map(filename, game))
	{
		perror("Failed to load the map");
		return ;
	}
	if (!map_check_rect(game))
		return ;
	if (!check_walls(game))
		return ;
	if (!map_check_valid(game))
		return ;
}
