/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_related.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:39:44 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 17:36:21 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	exit_error(char *msg, t_game *game)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	handle_close(game, EXIT_FAILURE);
}
