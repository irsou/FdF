/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:17:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/24 19:17:25 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (0);
}

void render_map(t_map *map)
{
	t_mlx	mlx;

	print_map(map);
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr) {
		perror("Error de MLX");
		return ;
	}
	mlx.win_width = 800;
	mlx.win_height = 600;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "FdF");
	if (!mlx.win_ptr)
	{
		perror("Error de ventana MLX");
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return ;
	}

	mlx.map = map;
  create_image(&mlx);
	if (!mlx.img.img_ptr)
	{
    perror("Error al crear la imagen");
    mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
    mlx_destroy_display(mlx.mlx_ptr);
    free(mlx.mlx_ptr);
    return ;
	}

	t_point start = {100, 100, 0};
	t_point end = {500, 800, 0};
	draw_line(&mlx.img, start, end, 0xFF0000, mlx.win_width, mlx.win_height);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);

	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
