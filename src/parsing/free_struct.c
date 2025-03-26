/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:12:45 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/25 22:24:19 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	free_map(t_game *game)
{
	int	h;

	h = 0;
	while (game->map && game->map[h] && h < game->map_height)
	{
		free(game->map[h]);
		h++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_visited(t_game *game)
{
	int	h;

	if (!game || !game->visited)
		return ;
	h = -1;
	while (++h < game->map_height)
	{
		if (game->visited[h])
			free(game->visited[h]);
	}
	free(game->visited);
	game->visited = NULL;
}
