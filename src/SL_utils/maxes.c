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
	int	max_h;
	
	max_h = 0;
	if (game->map)
	{
		while (game->map[max_h])
			max_h++;
	}
	game->map_height = max_h;
}

void	max_width(t_game *game)
{
	int	max_l;
	
	max_l = 0;
	if (game->map && game->map[0])
	{
		while (game->map[0][max_l])
			max_l++;
	}
	game->map_width = max_l;
}
