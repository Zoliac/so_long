/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:43 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 18:42:04 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	checker(char *file, t_game *game)
{
	check_filename(file);
	check_mapname(file);
	content_check(game);
	flood_fill(game);
}
