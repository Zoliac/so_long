/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:40:32 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 19:43:24 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "../../includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*gnl_strjoin(char *s1, char *s2);
char		*ft_clean_stash(char *stash);

#endif