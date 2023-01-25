/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:32:10 by gusimone          #+#    #+#             */
/*   Updated: 2022/12/24 15:45:57 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *data)
{
	if (data->width >= 500)
		data->coef = 2;
	else if (data->width >= 200 && data->width < 500)
		data->coef = 5;
	else if (data->width >= 50 && data->width < 200)
		data->coef = 20;
	else
		data->coef = 30;
	data->shift_x = 750;
	data->shift_y = 350;
	data->rotate_h = 0.8;
	data->rotate_v = 0.8;
}

int	close_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_all(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_V, WIN_H, "mlx 42");
	data->img = mlx_new_image(data->mlx, WIN_V, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	read_file(argv[argc - 1], data);
	init(data);
	draw(data, 1);
	mlx_hook(data->win, 17, (1l << 0), close_window, data);
	mlx_hook(data->win, 02, (1L << 0), deal_key, data);
	mlx_key_hook(data->win, deal_key, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}
