/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:55:46 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/24 15:11:07 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(t_fdf *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(data->matrix[j++]);
	free(data->matrix);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

void	free_all(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->matrix[i++]);
	free(data->matrix);
	free(data);
	exit(0);
}
