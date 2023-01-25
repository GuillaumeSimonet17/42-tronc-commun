/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:25 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/09 11:37:09 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_algo(t_list_a **lsta, t_list_b **lstb, int div)
{
	t_list_a	*la;
	int			i;
	int			len;

	i = 0;
	len = ft_lstsize(*lsta);
	la = *lsta;
	while (i < len)
	{
		if (ft_which_digit(lsta, lstb, la->index, div))
			la = *lsta;
		else
			la = la->next;
		i++;
	}
}

int	ft_which_digit(t_list_a **lsta, t_list_b **lstb, long n, int div)
{
	long	nb;

	nb = n;
	nb /= div;
	if (nb % 10 == 0)
	{
		pb(lsta, lstb);
		return (0);
	}
	else
		ra(lsta);
	return (1);
}

long	ft_convert_base_binary(long num)
{
	if (num >= 2)
		return (ft_convert_base_binary(num / 2) * 10 + num % 2);
	if (num % 2)
		return (1);
	return (0);
}

void	ft_all_in_lsta(t_list_a **lsta, t_list_b **lstb)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize_b(*lstb);
	while (i < len)
	{
		pa(lsta, lstb);
		i++;
	}
}
