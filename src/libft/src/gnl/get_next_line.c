/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:41:20 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 19:37:39 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_fd(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || !buff)
		{size_t		ft_strlen(const char *s);
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[bytes] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	if (ft_strlen(stash) - i + 1 > 0)
		str = malloc(ft_strlen(stash) - i + 1);
	else
		str = malloc(1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = read_fd(fd, stash);
	if (!stash)
		return (NULL);
	buffer = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (buffer);
}
