/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:33 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 21:25:14 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_mlx	*init_mlx(t_map *map)
{
	static t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		perror("Error de MLX");
		return (NULL);
	}
	mlx.scale = 20;
	mlx.win_width = 1920;
	mlx.win_height = 1080;
	mlx.offset_x_step = 0;
	mlx.offset_y_step = 0;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_width, mlx.win_height,
			"FdF");
	if (!mlx.win_ptr)
	{
		perror("Error de ventana MLX");
		mlx_destroy_display(mlx.mlx_ptr);
		return (NULL);
	}
	mlx.map = map;
	mlx.img.img_ptr = NULL;
	return (&mlx);
}
