/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:11:57 by lpatin            #+#    #+#             */
/*   Updated: 2025/02/08 23:40:29 by lpatin           ###   ########.fr       */
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
		if (!ft_isalnum(filename[i]) && !ft_isprint(filename))
			perror("Wrong file name, non printable characters found.");
	}
}

void	check_mapname(char *filename)
{
	int	i;
	char *extension;
	char *mapext;
	int	extlen;
	int	filelen;

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
