/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:56:42 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/24 14:15:02 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->rotate_v);
	*y = (*x + *y) * sin(data->rotate_h) - z;
}

int	max1(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}
