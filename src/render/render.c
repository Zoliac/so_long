/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 04:21:56 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 19:04:25 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	redraw_tile(t_game *game, int x, int y)
{
	void	*img;
	char	tile;

	img = NULL;
	tile = game->map[y][x];
	if (x == game->player_x && y == game->player_y)
		img = game->img_player;
	else if (tile == '1')
		img = game->img_wall;
	else if (tile == '0')
		img = game->img_floor;
	else if (tile == 'C')
		img = game->img_collect;
	else if (tile == 'E')
		img = game->img_exit;
	if (img)
		mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	x = 0;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
			redraw_tile(game, x, y);
	}
}
