/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:57:18 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/08 15:37:31 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(const char *str)
{
	long			i;
	int				sign;
	long long int	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	ft_parsing(char **strs, t_list_a **lsta, t_list_b **lstb)
{
	int	i;

	i = 0;
	if (ft_str_is_conform(strs[0]) == 0)
	{
		free(strs[0]);
		free(strs);
		return (ft_free_all(lsta, lstb));
	}
	if (strs[1])
	{
		while (strs[i])
		{
			if (ft_attribute_num_to_lst(lsta, lstb, strs[i]) == 0)
				return (ft_free_all(lsta, lstb));
			free(strs[i++]);
		}
	}
	else
	{
		if (ft_attribute_num_to_lst(lsta, lstb, strs[i]) == 0)
			return (ft_free_all(lsta, lstb));
		free(strs[i]);
	}
	return (1);
}

int	ft_attribute_num_to_lst(t_list_a **lsta, t_list_b **lstb, char *s)
{
	long long	num;

	num = ft_atol(s);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	ft_lstadd_back_a(lsta, num);
	ft_lstadd_back_b(lstb, num);
	return (1);
}
