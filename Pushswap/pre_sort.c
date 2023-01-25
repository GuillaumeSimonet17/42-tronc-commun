/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:58:27 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/09 11:09:31 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_b	*ft_pre_sort(t_list_a **lsta, t_list_b **lstb)
{
	t_list_b	*head;
	t_list_b	*l;
	int			n;

	n = 0;
	l = *lstb;
	head = *lstb;
	while (l->next)
	{
		if (l->num > l->next->num)
		{
			n = l->num;
			l->num = l->next->num;
			l->next->num = n;
			l = head;
		}
		else
			l = l->next;
	}
	ft_assign_index(lstb);
	ft_lsta_indexee(lsta, lstb);
	ft_clear_b(lstb);
	ft_sort_a(lsta, lstb);
	return (head);
}

t_list_b	*ft_assign_index(t_list_b **lstb)
{
	int			i;
	t_list_b	*tmp;

	i = 0;
	tmp = *lstb;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	return (*lstb);
}

t_list_a	*ft_lsta_indexee(t_list_a **lsta, t_list_b **lstb)
{
	t_list_a	*tmpa;
	t_list_b	*tmpb;

	tmpa = *lsta;
	tmpb = *lstb;
	while (tmpa)
	{
		if (tmpa->num == tmpb->num)
		{
			tmpa->index = tmpb->index;
			tmpb = tmpb->next;
			tmpa = *lsta;
		}
		else
			tmpa = tmpa->next;
		if (tmpb->next == NULL)
			break ;
	}
	while (tmpa)
	{
		if (tmpa->num == tmpb->num)
			tmpa->index = tmpb->index;
		tmpa = tmpa->next;
	}
	return (*lsta);
}

void	ft_sort_a(t_list_a **lsta, t_list_b **lstb)
{
	t_list_a	*la;
	int			div;
	int			max;
	int			loop;
	int			len_max;

	la = *lsta;
	div = 1;
	loop = 0;
	len_max = 0;
	while (la)
	{
		la->index = ft_convert_base_binary(la->index);
		la = la->next;
	}
	max = get_max(lsta);
	len_max = ft_long_num_max(max);
	while (loop < len_max)
	{
		ft_sort_algo(lsta, lstb, div);
		ft_all_in_lsta(lsta, lstb);
		div *= 10;
		loop++;
	}
}

int	ft_long_num_max(int max)
{
	int	len_max;

	len_max = 0;
	while (max > 0)
	{
		max /= 10;
		len_max++;
	}
	return (len_max);
}
