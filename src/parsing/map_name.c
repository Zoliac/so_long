/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:11:57 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/27 18:14:09 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (ft_isspace(filename[i]))
			return (ft_printf("%s", "Error\nFile name has spaces."), 0);
		if (!ft_isalnum(filename[i]) && !ft_isprint(filename[i]))
		{
			ft_printf("%s", "Wrong file name, non printable characters found.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_mapname(char *filename)
{
	int	filelen;

	if (!filename)
		return (perror("Error\nUsage : ./so_long 'map name'"), 0);
	filelen = ft_strlen(filename);
	if (filelen < 4 || ft_strncmp(filename + filelen - 4, ".ber", 4) != 0)
		return (ft_printf("%s", "Invalid extension, .ber map required.\n"), 0);
	return (1);
}
