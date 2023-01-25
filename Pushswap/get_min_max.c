/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:47:05 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/12 15:24:31 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list_a **lsta)
{
	int			nb_el;
	int			max;
	t_list_a	*l;
	int			i;

	i = 1;
	l = *lsta;
	nb_el = ft_lstsize(*lsta);
	max = l->index;
	while (i <= nb_el)
	{
		if (l->index > max)
			max = l->index;
		i++;
		l = l->next;
	}
	return (max);
}

int	get_min_num(t_list_a **lsta)
{
	int			nb_el;
	int			max;
	t_list_a	*l;
	int			i;

	i = 1;
	l = *lsta;
	nb_el = ft_lstsize(*lsta);
	max = l->num;
	while (i <= nb_el)
	{
		if (l->num < max)
			max = l->num;
		i++;
		l = l->next;
	}
	return (max);
}
