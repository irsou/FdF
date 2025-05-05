/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:23:19 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 21:29:58 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render_frame(t_mlx *mlx)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_image(mlx);
	if (!mlx->img.img_ptr)
	{
		perror("Error al crear la imagen");
		close_window(mlx);
		exit (0);
	}
	draw_wireframe(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}

void	render_map(t_map *map)
{
	static t_mlx	*mlx;

	mlx = init_mlx(map);
	if (!mlx)
		return ;
	render_frame(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 22, 1L << 17, resize_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_wheel, mlx);
	mlx_loop(mlx->mlx_ptr);
}
