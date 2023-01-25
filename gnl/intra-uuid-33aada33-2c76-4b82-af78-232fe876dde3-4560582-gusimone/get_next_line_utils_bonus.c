/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:31:47 by gusimone          #+#    #+#             */
/*   Updated: 2022/11/22 10:02:04 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc( size_t elementCount, size_t elementSize)
{
	unsigned char		*tab;
	size_t				i;

	i = 0;
	tab = (void *)malloc(elementCount * elementSize);
	if (!tab)
		return (NULL);
	while (i < elementCount * elementSize)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_is_new_line(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}
