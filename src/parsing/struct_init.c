/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:51:58 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 16:23:15 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_exit_pos(t_game *game)
{
	int	h;
	int	l;

	h = -1;
	while (++h < game->map_height)
	{
		l = -1;
		while (++l < game->map_width)
		{
			if (game->map[h][l] == 'E')
			{
				game->exit_x = l;
				game->exit_y = h;
			}
		}
	}
}

static void	init_positions(t_game *game)
{
	int	h;
	int	l;
	int	p_found;

	p_found = 0;
	h = -1;
	while (++h < game->map_height)
	{
		l = -1;
		while (++l < game->map_width)
		{
			if (game->map[h][l] == 'P' && !p_found)
			{
				game->player_x = l;
				game->player_y = h;
				p_found += 1;
			}
			else if (game->map[h][l] == 'P' && p_found)
			{
				ft_printf("Error\nToo many players in map.\n");
				handle_close(game, 2);
			}
		}
	}
	init_exit_pos(game);
}

void	collectibles(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->map_height)
	{
		w = -1;
		while (++w < game->map_width)
		{
			if (game->map[h][w] == 'C')
				game->collectibles_count++;
		}
	}
}

void	init_struct(t_game *game, char *filename)
{
	int	y;

	game->map = fill_map(filename, game);
	if (!game->map)
		return (free_struct(game));
	max_height(game);
	max_width(game);
	y = 0;
	game->visited = malloc(sizeof(int *) * game->map_height);
	if (!game->visited)
		exit(1);
	while (y < game->map_height)
	{
		game->visited[y] = ft_calloc(game->map_width, sizeof(int));
		y++;
	}
	collectibles(game);
	init_positions(game);
}

void	free_struct(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->visited)
	{
		i = 0;
		while (i < game->map_height)
			free(game->visited[i++]);
		free(game->visited);
		game->visited = NULL;
	}
}
