/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:44:10 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 16:11:12 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if ((int)start > ft_strlen((char *)s))
	{
		new = malloc(sizeof(char) * 1);
		if (!new)
			return (NULL);
		new[i] = 0;
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (s[start] && i < len)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}

static char	**ft_clear_all(char **strs, int a)
{
	while (a >= 0)
	{
		free(strs[a]);
		a--;
	}
	free(strs);
	return (0);
}

static int	ft_nb_str(char const *s, char c)
{
	int	nb_str;
	int	i;

	nb_str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			i++;
		}
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		nb_str++;
	}
	return (nb_str);
}

static char	**ft_scan(char const *s, char **strs, char c, int i)
{
	int	start;
	int	j;

	start = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[start] && s[start] != c)
			start ++;
		strs[j] = ft_substr(s, i, start - i);
		if (!strs[j])
			return (ft_clear_all(strs, j - 1));
		j++;
		i = start;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (0);
	strs = ft_calloc(sizeof(char *), ft_nb_str(s, c) + 1);
	if (!strs)
		return (NULL);
	return (ft_scan(s, strs, c, 0));
}
