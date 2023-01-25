/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:26:16 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 15:24:25 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_all(t_list_a **lsta, t_list_b **lstb)
{
	if (ft_check_doublon(lsta))
	{
		if (is_a_sorted(lsta))
		{
			ft_clear_b(lstb);
			return (-1);
		}
		if (ft_lstsize(*lsta) == 3)
			return (ft_sort3(lsta, lstb, 0));
		if (ft_lstsize(*lsta) == 5)
			return (ft_sort5(lsta, lstb));
		ft_pre_sort(lsta, lstb);
	}
	else
	{
		ft_clear_b(lstb);
		ft_clear_a(lsta);
		return (0);
	}
	return (1);
}

int	is_a_sorted(t_list_a **lsta)
{
	t_list_a	*tmp;

	tmp = *lsta;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (1);
}

int	ft_comp(int a, int b)
{
	if (a == b)
		return (0);
	return (1);
}

int	ft_check_doublon(t_list_a **lsta)
{
	t_list_a	*ptr1;
	t_list_a	*ptr2;

	ptr1 = *(lsta);
	ptr2 = ptr1->next;
	while (ptr1->next != NULL)
	{
		while (ptr2->next != NULL)
		{
			if (ft_comp(ptr1->num, ptr2->num) == 0)
				return (0);
			else
				ptr2 = ptr2->next;
		}
		if (ft_comp(ptr1->num, ptr2->num) == 0)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr1->next;
	}
	return (1);
}

int	ft_str_is_conform(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
