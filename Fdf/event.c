/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:54:06 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/24 15:46:23 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keycode, t_fdf *data)
{
	int			add;
	static int	cmd;
	static int	three_d;

	if (data->coef <= 5)
		add = 5;
	if (data->coef >= 50)
		add = 50;
	three_d = 1;
	if (keycode == 2)
		three_d = 0;
	if (keycode == 53)
		free_all(data);
	param_shift(data, keycode, cmd, add);
	if (keycode == 259)
		cmd = 1;
	if (keycode == 261)
		cmd = 0;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_V, WIN_V);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	draw(data, three_d);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	return (1);
}

int	mouse_hook(int keycode, int x, int y, t_fdf *data)
{
	x = y - y;
	if (data->coef <= 5)
	{
		data->coef++;
		mouse_hook(keycode, x, y, data);
		return (0);
	}
	if (data->coef >= 100)
	{
		data->coef--;
		mouse_hook(keycode, x, y, data);
		return (0);
	}
	if (keycode == 5)
		data->coef += 2;
	if (keycode == 4)
		data->coef -= 2;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_V, WIN_V);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	draw(data, 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	return (0);
}
