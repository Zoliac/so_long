/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_doable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:48:49 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/24 13:42:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	floodfill(int x_axis, int y_axis, t_game *game)
{
	max_h = max_height(game);
	max_l = max_width(game);
	if (x < 0 || x x >= max_l || y < 0 || y >= max_h)
		return (perror("Map isn't playable"));
	if (game->map[y][x] == '1' || game->map[y][x] == 'C' || game->map[y][x] == 'E')
		return (perror("Map isn't playable")); 
	
}

void	check_playability(char **map)
{
	
}