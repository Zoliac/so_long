/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:46:09 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 19:33:12 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (0);
	return (game->map[y][x] != '1');
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->map[new_y][new_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
}
