/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:27:24 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/31 17:30:04 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_mapbis(char ***map, int *i, int fd)
{
	char	*lines;
	size_t	len;
	int		loop;

	lines = NULL;
	len = 0;
	loop = 1;
	while (loop)
	{
		lines = get_next_line(fd);
		if (lines == NULL)
			break ;
		len = ft_strlen(lines);
		if (len > 0 && (lines[len - 1] == '\n' || lines[len - 1] == '\r'))
			lines[len - 1] = '\0';
		if (len == 0)
		{
			free(lines);
			continue ;
		}
		*map = add_line_map(*map, i, lines);
	}
}

char	**fill_map(char *filename, t_game *game)
{
	int		fd;
	char	**map;
	int		i;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror("Error\nProgram could not open the file.\n"), NULL);
	i = 0;
	map = NULL;
	fill_mapbis(&map, &i, fd);
	close(fd);
	if (i == 0)
		return (ft_printf("%s", "Error\nEmpty map.\n"), NULL);
	map = realloc_map(map, i + 1);
	game->map = map;
	close(fd);
	free_gnl_buffer(fd);
	return (game->map);
}

int	map_check_rect(t_game *game)
{
	int	h;

	if (!game->map || !game->map[0])
		return (ft_printf("%s", "Error\nEmpty Map.\n"), 0);
	h = 0;
	while (game->map[h])
	{
		if ((int)ft_strlen(game->map[h]) != game->map_width)
			return (ft_printf("%s", "Error\nMap should be rectngular.\n"), 0);
		h++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	h;
	int	l;

	if (!game->map || !game->map[0])
		return (ft_printf("%s", "Error\nInvalid map.\n"), 0);
	l = 0;
	while (l < game->map_width)
	{
		if (game->map[0][l] != '1' || game->map[game->map_height - 1][l] != '1')
			return (ft_printf("%s", "Error\nHorizontal wall invalid.\n"), 0);
		l++;
	}
	h = 0;
	while (h < game->map_height)
	{
		if (game->map[h][0] != '1' || game->map[h][game->map_width - 1] != '1')
			return (ft_printf("%s", "Error\nVertical wall invalid.\n"), 0);
		h++;
	}
	return (1);
}

int	map_check_valid(t_game *game)
{
	int	h;
	int	l;

	h = -1;
	while (++h < game->map_height)
	{
		l = -1;
		while (++l < game->map_width)
		{
			if (!ft_strchr("01CEP", game->map[h][l]))
				return (ft_printf("%s",
						"Error\nInvalid character in the map.\n"), 0);
		}
	}
	return (1);
}
