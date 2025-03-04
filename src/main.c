/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:41 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 19:12:20 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game *game;
	char *filename = argv[1];

	game = malloc(sizeof(t_game));
	if (!filename)
		return(ft_printf("%s\n", strerror(errno)));
	game = NULL;
	if (argc < 2)
		return(perror("Usage : ./so_long <map name>"), 0);
	if (!argv)
		return (0);
	init_struct(game, filename);
	checker(filename, game);
}
