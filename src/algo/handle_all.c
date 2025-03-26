/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:39:55 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 21:25:35 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	handle_close(t_game *game, int ec)
{
	if (game->win)
	{
		mlx_destroy_image(game->mlx, game->img_collect);
		mlx_destroy_image(game->mlx, game->img_exit);
		mlx_destroy_image(game->mlx, game->img_floor);
		mlx_destroy_image(game->mlx, game->img_wall);
		mlx_destroy_image(game->mlx, game->img_player);
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game)
		free_struct(game);
	if (game)
		free(game);
	exit(ec);
}

int	valid_move(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	if (is_valid_move(game, new_x, new_y))
	{
		if (game->map[new_y][new_x] == 'C')
			game->collectibles_count--;
		if (game->map[new_y][new_x] == 'E' && game->collectibles_count == 0)
			handle_close(game, 2);
		update_player_position(game, new_x, new_y);
		redraw_tile(game, old_x, old_y);
		redraw_tile(game, new_x, new_y);
		return (1);
	}
	return (0);
}

int	handle_keys(int key, t_game *game)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	old_x = 0;
	old_y = 0;
	new_x = game->player_x;
	new_y = game->player_y;
	if (key == ESCAPE)
		handle_close(game, 2);
	if (key == W_KEY)
		new_y--;
	if (key == S_KEY)
		new_y++;
	if (key == A_KEY)
		new_x--;
	if (key == D_KEY)
		new_x++;
	valid_move(game, new_x, new_y);
	if (valid_move(game, new_x, new_y)
		&& (key == D_KEY || key == A_KEY || key == W_KEY || key == S_KEY))
		steps_counter(game, old_x, old_y);
	return (0);
}

int	close_game_click(t_game *game)
{
	handle_close(game, 2);
	return (0);
}

void	handle_input(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, handle_keys, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask,
		close_game_click, game);
}
