/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_interact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:28:32 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 23:04:31 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	arrow_press(int keycode, void *param)
{
	t_mlx	*mlx;
	int		step;
	int		max_x;
	int		max_y;

	mlx = (t_mlx *)param;
	step = (100.0 / mlx->scale);
	if (!mlx || !mlx->map)
		return (1);
	max_x = (mlx->map->width * mlx->scale) / 2;
	max_y = (mlx->map->height * mlx->scale) / 2;
	if (keycode == 65361 && mlx->offset_x_step > -max_x)
		mlx->offset_x_step -= step;
	else if (keycode == 65363 && mlx->offset_x_step < max_x)
		mlx->offset_x_step += step;
	else if (keycode == 65362 && mlx->offset_y_step > -max_y)
		mlx->offset_y_step -= step;
	else if (keycode == 65364 && mlx->offset_y_step < max_y)
		mlx->offset_y_step += step;
	render_frame(mlx);
	return (0);
}

int	key_press(int keycode, void *param)
{
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
