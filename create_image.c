/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:49:41 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/21 12:09:51 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= mlx->win_width || y >= mlx->win_height)
		return ;
	dst = mlx->img.addr + (y * mlx->img.line_length + x
			*(mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_loop(t_mlx *mlx, t_line *l)
{
	int		e2;

	while (l->start.x != l->end.x || l->start.y != l->end.y)
	{
		my_mlx_pixel_put(mlx, l->start.x, l->start.y, l->color);
		e2 = l->err;
		if (e2 > -l->dx)
		{
			l->err -= l->dy;
			l->start.x += l->sx;
		}
		if (e2 < l->dy)
		{
			l->err += l->dx;
			l->start.y += l->sy;
		}
	}
}

void	draw_line(t_mlx *mlx, t_point start, t_point end, int color)
{
	t_line	line;

	line.start = start;
	line.end = end;
	line.color = color;
	line.dx = abs(end.x - start.x);
	line.dy = abs(end.y - start.y);
	if (start.x < end.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (start.y < end.y)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	draw_line_loop(mlx, &line);
	my_mlx_pixel_put(mlx, line.end.x, line.end.y, color);
}

void	create_image(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width,
			mlx->win_height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}
