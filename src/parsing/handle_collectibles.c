/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:28:53 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 22:01:21 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	collectible_found(t_game *game)
{
	if (game->collectibles_count == 0)
		return (0);
	return (ft_putendl_fd("Error\nMap not playable, no collectible found\n", 
			2), 1);
}

int	count_collectibles(t_game *g)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = -1;
	while (++y < g->map_height)
	{
		x = -1;
		while (++x < g->map_width)
			if (g->map[y][x] == 'C')
				count++;
	}
	return (count);
}
