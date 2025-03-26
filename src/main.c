/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:41 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 19:58:04 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*filename;

	filename = argv[1];
	if (argc < 2)
		return (ft_printf("%s\n", "Usage : ./so_long <map name>"), 0);
	if (!filename)
		return (ft_printf("%s\n", strerror(errno)));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	init_struct(game, filename);
	if (!checker(filename, game))
	{
		free_struct(game);
		free(game);
		return (1);
	}
	ft_printf("%s\n", "Map is valid and ready to be played.");
	game->map[game->player_y][game->player_x] = '0';
	init_all(game);
	free_struct(game);
	free(game);
	return (0);
}
