/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_doable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:48:49 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 22:04:26 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	enqueue(t_queue *q, int x, int y)
{
	t_queue_node	*new_node;

	new_node = malloc(sizeof(t_queue_node));
	if (!new_node)
	{
		ft_printf("%s", "Couldn't create a new node \
						for the floodfill algorithm.");
		return (1);
	}
	new_node->y = y;
	new_node->x = x;
	new_node->next = NULL;
	if (q->tail)
		q->tail->next = new_node;
	else
		q->head = new_node;
	q->tail = new_node;
	return (1);
}

static t_queue_node	*dequeue(t_queue *q)
{
	t_queue_node	*temp;

	if (!q->head)
		return (NULL);
	temp = q->head;
	q->head = q->head->next;
	if (!q->head)
		q->tail = NULL;
	return (temp);
}

int	exit_condition(int exit_count)
{
	if (exit_count != 1)
		return (ft_putendl_fd("Error\nMap not playable, no exit found or multiple exits found\n", 2), 0);
	return (1);
}


static void	process_directions(t_game *g, int px, int py, t_queue *q, int *ec)
{
	int	direction_index;
	int	nx;
	int	ny;
	int	delta_x;
	int	delta_y;

	direction_index = -1;
	while (++direction_index < 4)
	{
		delta_x = (direction_index == 0) - (direction_index == 1);
		delta_y = (direction_index == 2) - (direction_index == 3);
		nx = px + delta_x;
		ny = py + delta_y;
		if (nx >= 0 && nx < g->map_width && ny >= 0 && ny < g->map_height
			&& g->map[ny][nx] != '1' && !g->visited[ny][nx])
		{
			g->visited[ny][nx] = 1;
			enqueue(q, nx, ny);
			if (g->map[ny][nx] == 'E')
				(*ec)++;
			if (g->map[ny][nx] == 'C')
				g->collectibles_count--;
		}
	}
}

void	flood_fill(t_game *game)
{
	t_queue			*q;
	t_queue_node	*current;
	int				exit_count;

	exit_count = 0;
	game->collectibles_count = count_collectibles(game);
	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		return ;
	q->head = NULL;
	q->tail = NULL;
	enqueue(q, game->player_x, game->player_y);
	game->visited[game->player_y][game->player_x] = 1;
	while (q->head)
	{
		current = dequeue(q);
		process_directions(game, current->x, current->y, q, &exit_count);
		free(current);
	}
	if (!exit_count)
		exit_error("No valid path to exit", game);
	if (game->collectibles_count > 0)
		exit_error("Unreachable collectibles", game);
	free(q);
}
