/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:04:12 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 16:12:49 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_remove_first_b(t_list_b **lstb)
{
	t_list_b	*ptr;
	t_list_b	*ptr2;

	ptr = *lstb;
	ptr2 = ptr->next;
	*lstb = ptr2;
	free(ptr);
	return (*lstb);
}

t_list_a	*pa(t_list_a **lsta, t_list_b **lstb)
{
	t_list_a	*tmp;
	t_list_b	*tmpb;

	tmp = *lsta;
	tmpb = *lstb;
	tmp = ft_create_elem_a(tmpb->num);
	if (!lstb)
		return (0);
	tmp->index = tmpb->index;
	if (!lsta)
		tmp->next = NULL;
	else
		tmp->next = *lsta;
	*lsta = tmp;
	ft_remove_first_b(lstb);
	write(1, "pa\n", 3);
	return (*lsta);
}

t_list_a	*ft_remove_first_a(t_list_a **lsta)
{
	t_list_a	*ptr;
	t_list_a	*ptr2;

	ptr = *lsta;
	ptr2 = ptr->next;
	*lsta = ptr2;
	free(ptr);
	return (*lsta);
}

t_list_b	*pb(t_list_a **lsta, t_list_b **lstb)
{
	t_list_a	*tmp;
	t_list_b	*tmpb;

	if (!lsta)
		return (0);
	tmp = *lsta;
	tmpb = *lstb;
	tmpb = ft_create_elem_b(tmp->num);
	tmpb->index = tmp->index;
	if (!lstb)
		tmpb->next = NULL;
	else
		tmpb->next = *lstb;
	*lstb = tmpb;
	ft_remove_first_a(lsta);
	write(1, "pb\n", 3);
	return (*lstb);
}
