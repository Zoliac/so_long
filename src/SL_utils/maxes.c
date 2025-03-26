/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:18:31 by marvin            #+#    #+#             */
/*   Updated: 2025/02/17 17:18:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	max_height(t_game *game)
{
	int	h;

	h = 0;
	if (game->map)
	{
		while (game->map[h])
			h++;
	}
	game->map_height = h;
}

void	max_width(t_game *game)
{
	int	h;
	int	max_l;

	h = 0;
	max_l = 0;
	if (!game->map || !game->map[0])
		exit (1);
	while (game->map[h])
	{
		if ((int)ft_strlen(game->map[h]) > max_l)
			max_l = ft_strlen(game->map[h]);
		h++;
	}
	h = 0;
	while (game->map[h])
	{
		if ((int)ft_strlen(game->map[h]) != max_l)
			exit (1);
		h++;
	}
	game->map_width = max_l;
}
