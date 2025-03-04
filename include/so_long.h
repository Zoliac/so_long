/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:51 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 18:28:55 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "../src/libft/includes/libft.h"
#include "../src/minilibx-linux/mlx.h"

typedef struct s_game {
	char	**map;
	int		**visited;
	int		map_height;
	int		map_width;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
}			t_game;

typedef struct	s_queue_node{
	int					x;
	int					y;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue{
	t_queue_node	*head;
	t_queue_node	*tail;
}					t_queue;

//Parsing

void				flood_fill(t_game *game);
char				**fill_map(char *filename, t_game *game);
int					map_check_rect(t_game *game);
int					check_walls(t_game *game);
int					map_check_valid(t_game *game);
void				content_check(t_game *game);
void				check_filename(char *filename);
void				check_mapname(char *filename);
void				init_struct(t_game *game, char *filename);
void				checker(char *file, t_game *game);

//Utils

char				**add_line_map(char **map, int *i, char *line);
char				**realloc_map(char **map, int size);
void				max_height(t_game *game);
void				max_width(t_game *game);


#endif