/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:49:41 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 21:13:24 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	create_image(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width,
			mlx->win_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}
