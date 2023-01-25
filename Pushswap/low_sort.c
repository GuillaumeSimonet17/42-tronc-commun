/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:00:56 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 16:06:27 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort3(t_list_a **lsta, t_list_b **lstb, int true)
{
	t_list_a	*tmpa;

	tmpa = *lsta;
	if (is_a_sorted(lsta))
		return (1);
	if (true == 0)
		ft_clear_b(lstb);
	if (tmpa->num < tmpa->next->num)
	{
		ra(lsta);
		ra(lsta);
		if (is_a_sorted(lsta) == 0)
			sa(lsta);
	}
	else
	{
		if (tmpa->num > tmpa->next->next->num)
		{
			ra(lsta);
			if (is_a_sorted(lsta))
				return (1);
		}
		sa(lsta);
	}
	return (1);
}
//  Checker met error quand c'est deja sorted

int	ft_sort5(t_list_a **lsta, t_list_b **lstb)
{
	t_list_a	*tmp;
	int			i;
	int			a;
	int			min;

	i = 0;
	tmp = *lsta;
	ft_clear_b(lstb);
	min = get_min_num(lsta);
	a = 0;
	while (a != 2)
	{
		ft_sort5bis(lsta, lstb, i, min);
		i = 0;
		a++;
		tmp = *lsta;
	}
	i = 0;
	ft_sort3(lsta, lstb, 1);
	pa(lsta, lstb);
	pa(lsta, lstb);
	return (1);
}

int	ft_sort5bis(t_list_a **lsta, t_list_b **lstb, int i, int min)
{
	t_list_a	*tmp;

	tmp = *lsta;
	min = get_min_num(lsta);
	while (tmp)
	{
		if (tmp->num == min)
		{
			while (i > 0)
			{
				ra(lsta);
				i--;
			}
			pb(lsta, lstb);
		}
		tmp = tmp->next;
		i++;
	}
	return (1);
}
