/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:27:24 by blakehal          #+#    #+#             */
/*   Updated: 2022/12/23 18:57:44 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_scan(char const *s, char **strs, char c, int i)
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
