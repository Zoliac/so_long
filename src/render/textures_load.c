/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:11:44 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 19:02:06 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	texture_load(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->img_size, &game->img_size);
	if (!game->img_wall)
		return (ft_printf("%s\n", "Couldn't load wall texture (filename)."));
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm",
			&game->img_size, &game->img_size);
	if (!game->img_collect)
		return (ft_printf("%s\n", "Couldn't load collectible texture ."));
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->img_size, &game->img_size);
	if (!game->img_exit)
		return (ft_printf("%s\n", "Couldn't load exit texture (filename)."));
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm",
			&game->img_size, &game->img_size);
	if (!game->img_floor)
		return (ft_printf("%s\n", "Couldn't load floor texture (filename)."));
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&game->img_size, &game->img_size);
	if (!game->img_player)
		return (ft_printf("%s\n", "Couldn't load player texture (filename)."));
	return (ft_printf("%s\n", "Textures succesfully loaded."));
}
