/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:25:58 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/05 13:25:58 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_a	*ft_create_elem_a(int num)
{
	t_list_a	*new;

	new = malloc(sizeof(t_list_a));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list_b	*ft_create_elem_b(int num)
{
	t_list_b	*new;

	new = malloc(sizeof(t_list_b));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_a(t_list_a **lsta, int num)
{
	t_list_a	*tmp;

	tmp = *lsta;
	if (!*lsta)
	{
		tmp = ft_create_elem_a(num);
		*lsta = tmp;
		return ;
	}
	tmp = (*lsta);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem_a(num);
}

void	ft_lstadd_back_b(t_list_b **lstb, int num)
{
	t_list_b	*tmp;

	tmp = *lstb;
	if (!*lstb)
	{
		tmp = ft_create_elem_b(num);
		*lstb = tmp;
		return ;
	}
	tmp = (*lstb);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem_b(num);
}
