/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:06:55 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/04 19:44:32 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "../../includes/libft.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*gnl_strjoin(char *s1, char *s2);
char		*ft_clean_stash(char *stash);

#endif