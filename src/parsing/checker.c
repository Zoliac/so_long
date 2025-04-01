/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:43 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 18:13:51 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	error_map_el(int p, int e, int c)
{
	if (p != 1)
		return (0);
	if (e != 1)
		return (0);
	if (c < 1)
		return (0);
	return (1);
}

int	validate_map_elements(t_game *game)
{
	int	h;
	int	l;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	h = -1;
	h = 0;
	while (++h < game->map_height)
	{
		l = -1;
		while (++l < game->map_width)
		{
			p += (game->map[h][l] == 'P');
			e += (game->map[h][l] == 'E');
			c += (game->map[h][l] == 'C');
		}
	}
	return (error_map_el(p, e, c));
}

int	content_check(t_game *game)
{
	if (game->map)
	{
		if (!map_check_rect(game))
			return (0);
		if (!check_walls(game))
			return (0);
		if (!map_check_valid(game))
			return (0);
	}
	return (1);
}

int	checker(char *file, t_game *game)
{
	if (!check_filename(file) || !check_mapname(file))
		return (ft_printf(" Invalid file name.\n"), 0);
	if (!content_check(game))
		return (0);
	if (!validate_map_elements(game))
		return (ft_printf("Error\nWrong map, 1P required, 1+C, 1E.\n"), 0);
	flood_fill(game);
	return (1);
}
