/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:46:39 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 21:26:14 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putendl_fd("No display found.", 2);
		handle_close(game, 2);
	}
	game->img_size = 32;
	game->win = mlx_new_window(game->mlx,
			game->map_width * game->img_size,
			game->map_height * game->img_size,
			"So Long");
	init_player_position(game);
}
