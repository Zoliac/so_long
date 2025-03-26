/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:05:28 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 19:29:31 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	steps_counter(t_game *game, int old_px, int old_py)
{
	if (game->player_x != old_px && game->player_y != old_py)
		game->steps_count++;
	ft_printf("%d", game->steps_count);
	ft_printf("\n");
}
