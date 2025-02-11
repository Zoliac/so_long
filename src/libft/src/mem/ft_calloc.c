/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:42:44 by lpatin            #+#    #+#             */
/*   Updated: 2024/12/06 18:42:42 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
	size_t idk = 5;
	size_t taille = sizeof(int);
	int *tab;

	tab = (int *)ft_calloc(idk, taille);
	if (!tab)
	{
		printf("Calloc echoue\n");
		return (1);
	}
	printf("%p",tab);
	free(tab);
	return (0);
}*/