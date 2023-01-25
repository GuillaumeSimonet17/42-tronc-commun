/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:25:53 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 15:43:43 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*bloc;

	bloc = malloc((elementCount * elementSize) + 1);
	if (!bloc)
		return (NULL);
	return (bloc);
}

int	ft_lstsize(t_list_a *lsta)
{
	int	i;

	i = 0;
	while (lsta)
	{
		i++;
		lsta = lsta->next;
	}
	return (i);
}

int	ft_lstsize_b(t_list_b *lstb)
{
	int	i;

	i = 0;
	while (lstb)
	{
		i++;
		lstb = lstb->next;
	}
	return (i);
}

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
