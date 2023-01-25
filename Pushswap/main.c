/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:26:18 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/12 14:54:14 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**strs;
	int			a;
	t_list_a	*lsta;
	t_list_b	*lstb;

	a = 1;
	lsta = NULL;
	lstb = NULL;
	strs = NULL;
	if (argc < 2)
		return (0);
	while (argv[a])
	{
		strs = ft_split(argv[a], ' ');
		if (ft_parsing(strs, &lsta, &lstb) == 0)
			return (write(2, "Error\n", 6), 0);
		free(strs);
		a++;
	}
	a = 0;
	if (ft_check_all(&lsta, &lstb) == 0)
		return (write(2, "Error\n", 6), 0);
	if (ft_check_all(&lsta, &lstb) == -1)
		return (ft_clear_a(&lsta), 0);
	return (ft_clear_a(&lsta), 0);
}
