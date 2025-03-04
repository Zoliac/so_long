/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:11:57 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 20:32:18 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (ft_isspace(filename[i]))
			perror("File name should not have spaces.");
		if (!ft_isalnum(filename[i]) && !ft_isprint(filename[i]))
			perror("Wrong file name, non printable characters found.");
		i++;
	}
}

void	check_mapname(char *filename)
{
	int		i;
	char	*extension;
	int		extlen;
	int		filelen;

	extension = ".ber";
	extlen = 3;
	i = 0;
	filelen = 0;
	if (!filename)
		return ;
	if (filelen < extlen)
		return ;
	while (filename[filelen])
		filelen++;
	if (ft_strncmp(filename + filelen - extlen, extension, extlen) == 0)
		perror("Wrong file extension, file should be on .ber format.");
}
