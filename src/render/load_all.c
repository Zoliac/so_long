/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:10:33 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 15:57:57 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_all(t_game *game)
{
	game->collectibles_count = count_collectibles(game);
	init_mlx(game);
	texture_load(game);
	render_map(game);
	handle_input(game);
	mlx_loop(game->mlx);
}
