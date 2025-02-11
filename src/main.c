/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:41 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/08 23:41:12 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game *game;
	char *filename = argv[1];

	if (!filename)
	{
		ft_printf("%s\n", strerror(errno));
		return ;
	}
	game = NULL;
	if (argc < 2)
		perror("Usage : ./so_long <map name>");
	if (!argv)
		return ;
	checker(argc, filename);
}
