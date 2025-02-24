/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:51 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/21 12:49:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "../src/libft/includes/libft.h"
#include "../src/minilibx-linux/mlx.h"

typedef struct s_game {
	char	**map;
	bool	**visited;
	int		map_height;
	int		map_width;
	int		collectibles;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
}			t_game;

#endif