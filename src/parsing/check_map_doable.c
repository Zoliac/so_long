/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_doable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:48:49 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 18:12:40 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void enqueue(t_queue *q, int x, int y)
{
	t_queue_node *new_node;

	new_node = malloc(sizeof(t_queue_node));
	if (!new_node)
	{
		perror("Couldn't create a new node for the floodfill algorithm.");
		exit(1);
	}
	new_node->y = y;
	new_node->x = x;
	new_node->next = NULL;
	if (q->tail)
		q->tail->next = new_node;
	else
		q->head = new_node;
	q->tail = new_node;
}

static t_queue_node *dequeue(t_queue *q)
{
	t_queue_node *temp;

	if (!q->head)
		return NULL;
	temp = q->head;
	q->head = q->head->next;
	if (!q->head)
		q->tail = NULL;
	return (temp);
}

static void	process_directions(t_game *game, int player_x, int player_y, t_queue *queue)
{
	int	direction_index;
	int	new_x;
	int	new_y;
	int	delta_x;
	int	delta_y;

	direction_index = -1;
	while (++direction_index < 4)
	{
		delta_x = (direction_index == 0) - (direction_index == 1);
		delta_y = (direction_index == 2) - (direction_index == 3);
		new_x = player_x + delta_x;
		new_y = player_y + delta_y;
		if (new_x >= 0 && new_x < game->map_width && new_y >= 0 && new_y < game->map_height
			&& game->map[new_y][new_x] != '1' && !game->visited[new_y][new_x])
		{
			game->visited[new_y][new_x] = 1;
			enqueue(queue, new_x, new_y);
		}
	}
}

void flood_fill(t_game *game)
{
	t_queue *q;
	
	q = (t_queue *)malloc(sizeof(t_queue));
	if (!q)
		return;
	q->head = NULL;
	q->tail = NULL;
	enqueue(q, game->player_x, game->player_y);
	game->visited[game->player_y][game->player_x] = 1;
	while (q->head)
	{
		t_queue_node *current = dequeue(q);
		process_directions(game, current->x, current->y, q);
		free(current);
	}
	free(q);
}
