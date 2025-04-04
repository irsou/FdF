/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:49:41 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/01 21:49:41 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color, int width, int height)
{
	char    *dst;

	if (x < 0 || y < 0  || x >= width || y >= height)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_line(t_img *img, t_point start, t_point end, int color, int width, int height)
{
	int dx = abs(end.x - start.x);
	int dy = -abs(end.y - start.y);
	int sx = start.x < end.x ? 1 : -1;
	int sy = start.y < end.y ? 1 : -1;
	int err = dx + dy;
	int e2;

	while (1)
	{
		my_mlx_pixel_put(img, start.x, start.y, color, width, height);
		if (start.x == end.x && start.y == end.y)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			if (start.x == end.x)
				break;
			err += dy;
			start.x += sx;
		}
		if (e2 <= dx)
		{
			if (start.y == end.y)
					break;
			err += dx;
			start.y += sy;
		}
	}
}

void    clear_image(t_img *img, int color, int width, int height)
{
	int x, y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, color, width, height);
			x++;
		}
		y++;
	}
}

void    create_image(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width, mlx->win_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, 
																	&mlx->img.bits_per_pixel, 
																	&mlx->img.line_length, 
																	&mlx->img.endian);
}

