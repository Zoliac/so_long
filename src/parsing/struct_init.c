/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:51:58 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 18:34:35 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_struct(t_game *game, char *filename)
{
	game->map = fill_map(filename, game);
	game->visited = 0;
	max_height(game);
	max_width(game);
	game->exit_x = 0;
	game->exit_y = 0;
	game->player_x = 0;
	game->player_y = 0;
}
