/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:26:09 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 16:13:34 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*sa(t_list_a **lsta)
{
	t_list_a	*tmp;
	int			n;

	tmp = *lsta;
	if (!lsta || tmp->next == NULL)
		return (NULL);
	n = tmp->next->num;
	tmp->next->num = tmp->num;
	tmp->num = n;
	write(1, "sa\n", 3);
	return (*lsta);
}

t_list_b	*sb(t_list_b **lstb)
{
	t_list_b	*tmp;
	int			n;

	tmp = *lstb;
	if (!lstb || tmp->next == NULL)
		return (NULL);
	n = tmp->next->num;
	tmp->next->num = tmp->num;
	tmp->num = n;
	write(1, "sb\n", 3);
	return (*lstb);
}

t_list_a	*ra(t_list_a **lsta)
{
	t_list_a	*last;
	t_list_a	*first;

	first = *lsta;
	last = *lsta;
	while (last->next)
		last = last->next;
	*lsta = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
	return (*lsta);
}
