/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:59:39 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 13:02:03 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_all(t_list_a **lsta, t_list_b **lstb)
{
	ft_clear_b(lstb);
	ft_clear_a(lsta);
	return (0);
}

void	ft_clear_b(t_list_b **lstb)
{
	t_list_b	*ptr;

	if (!lstb)
		return ;
	ptr = *lstb;
	while (ptr)
	{
		*lstb = ptr->next;
		ft_lstdelone_b(ptr);
		ptr = *lstb;
	}
}

void	ft_clear_a(t_list_a **lsta)
{
	t_list_a	*ptr;

	if (!lsta)
		return ;
	ptr = *lsta;
	while (ptr)
	{
		*lsta = ptr->next;
		ft_lstdelone_a(ptr);
		ptr = *lsta;
	}
}

void	ft_lstdelone_b(t_list_b *lstb)
{
	if (lstb)
	{
		lstb->num = 0;
		lstb->index = -1;
		free(lstb);
	}
}

void	ft_lstdelone_a(t_list_a *lsta)
{
	if (lsta)
	{
		lsta->num = 0;
		lsta->index = -1;
		free(lsta);
	}
}
