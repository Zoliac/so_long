/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:50:37 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 19:21:10 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**add_line_map(char **map, int *i, char *line)
{
	char	**new_map;
	int		j;

	new_map = malloc(sizeof(char *) * (*i + 1));
	if (!new_map)
		return (NULL);
	j = -1;
	while (++j < *i)
		new_map[j] = map[j];
	new_map[*i] = line;
	free(map);
	(*i)++;
	return (new_map);
}

char	**realloc_map(char **map, int size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * size);
	if (!new_map)
		return (NULL);
	i = 0;
	while (map && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = NULL;
	free(map);
	return(new_map);
}
