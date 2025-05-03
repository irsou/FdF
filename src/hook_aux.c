/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:23:19 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/03 09:22:28 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(0);
}

int	arrow_press(int keycode, void *param)
{
	t_mlx	*mlx;
	int		step;

	mlx = (t_mlx *)param;
	step = 1;
	if (mlx->offset_x_step > -((mlx->map->width * mlx->scale) / 2))
	{
		if (keycode == 65361)
			mlx->offset_x_step -= step;
		else if (keycode == 65362)
			mlx->offset_y_step -= step;
	}
	else if (mlx->offset_y_step > -((mlx->map->height * mlx->scale) / 2))
	{
		if (keycode == 65364)
			mlx->offset_y_step += step;
		else if (keycode == 65363)
			mlx->offset_x_step += step;
	}
	render_frame(mlx);
	return (0);
}

int	esc_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 65307)
		return (esc_press(keycode, param));
	else if (keycode == 65361 || keycode == 65362 || keycode == 65363
		|| keycode == 65364)
		return (arrow_press(keycode, param));
	return (0);
}

int	resize_handler(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	render_frame(mlx);
	return (0);
}

int	mouse_wheel(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)param;
	if (!mlx)
	{
		printf("Error: mlx es NULL\n");
		return (0);
	}
	if (button == 5)
	{
		if (mlx->scale > 0.2)
			mlx->scale = mlx->scale - 0.4;
		render_frame(mlx);
	}
	else if (button == 4)
	{
		if (mlx->scale < 100.0)
			mlx->scale = mlx->scale + 0.4;
		render_frame(mlx);
	}
	return (0);
}
