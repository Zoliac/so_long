/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:08:51 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 16:21:12 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "../src/libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/XKBlib.h>

# define ESCAPE XK_Escape
# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define S_KEY 115

typedef struct s_game
{
	char	**map;
	int		**visited;
	int		map_height;
	int		map_width;
	int		exit_x;
	int		exit_y;
	int		player_x;
	int		player_y;
	int		img_size;
	int		collectibles_count;
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		steps_count;
	int		exit_count;
}			t_game;

typedef struct s_queue_node
{
	int					x;
	int					y;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue
{
	t_queue_node	*head;
	t_queue_node	*tail;
}					t_queue;

//Parsing

char				**fill_map(char *filename, t_game *game);
int					map_check_rect(t_game *game);
int					check_walls(t_game *game);
int					map_check_valid(t_game *game);
int					content_check(t_game *game);
int					check_filename(char *filename);
int					check_mapname(char *filename);
int					checker(char *file, t_game *game);
int					validate_map_elements(t_game *game);
void				flood_fill(t_game *game);
void				init_struct(t_game *game, char *filename);
void				free_map(t_game *game);
void				free_visited(t_game *game);
void				free_struct(t_game *game);

//Utils

char				**add_line_map(char **map, int *i, char *line);
char				**realloc_map(char **map, int size);
void				max_height(t_game *game);
void				max_width(t_game *game);

//MLX

void				init_all(t_game *game);
void				init_mlx(t_game *game);
int					texture_load(t_game *game);
void				redraw_tile(t_game *game, int x, int y);
void				init_player_position(t_game *game);
void				render_map(t_game *game);

//Handle

void				handle_input(t_game *game);
void				handle_close(t_game *game, int ec);
int					handle_keys(int key, t_game *game);
int					close_game_click(t_game *game);
int					collectible_found(t_game *game);
int					count_collectibles(t_game *g);
void				exit_error(char *msg, t_game *game);

//Movement

int					is_valid_move(t_game *game, int x, int y);
void				update_player_position(t_game *game, int new_x, int new_y);
void				steps_counter(t_game *game, int old_px, int old_py);

#endif