/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:50:37 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 22:04:49 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**add_line_map(char **map, int *i, char *line)
{
	char	**new_map;
	int		j;

	new_map = ft_calloc(*i + 2, sizeof(char *));
	if (!new_map)
		return (NULL);
	j = 0;
	while (map && map[j])
	{
		new_map[j] = map[j];
		j++;
	}
	new_map[j] = line;
	new_map[j + 1] = NULL;
	free(map);
	*i += 1;
	return (new_map);
}

char	**realloc_map(char **map, int size)
{
	char	**new_map;
	int		i;

	if (size <= 0)
		return (NULL);
	new_map = ft_calloc(size, sizeof(char *));
	if (!new_map)
		return (NULL);
	i = -1;
	while (map && map[++i] && i < size - 1)
		new_map[i] = map[i];
	if (map)
		free(map);
	return (new_map);
}

void	init_player_position(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
		}
	}
}
