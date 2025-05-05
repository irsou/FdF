/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:24:30 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 21:24:43 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	iso_convert(t_point p, t_mlx *mlx)
{
	t_point	iso;
	int		offset_x;
	int		offset_y;

	offset_x = (mlx->win_width / 2) + mlx->offset_x_step;
	offset_y = (mlx->win_height / 4) + mlx->offset_y_step;
	iso.x = (p.x - p.y) * cos(0.523599) * mlx->scale;
	iso.y = (p.x + p.y) * sin(0.523599) * mlx->scale - p.z * mlx->scale / 2;
	iso.z = p.z;
	iso.color = p.color;
	iso.x += offset_x;
	iso.y += offset_y;
	return (iso);
}

void	draw_line_between_points(t_draw *draw, int next_x, int next_y)
{
	t_point	next;

	next.x = next_x;
	next.y = next_y;
	next.z = draw->map->matrix[next.y][next.x].z;
	next.color = draw->map->matrix[next.y][next.x].color;
	next = iso_convert(next, draw->mlx);
	draw_line(draw->mlx, draw->current, next);
}

static void	set_current_point(t_draw *draw, int x, int y, t_mlx *mlx)
{
	draw->current.x = x;
	draw->current.y = y;
	draw->current.z = draw->map->matrix[y][x].z;
	draw->current.color = draw->map->matrix[y][x].color;
	draw->current = iso_convert(draw->current, mlx);
	pixel_put(mlx, draw->current.x, draw->current.y,
		draw->current.color);
}

static void	draw_adjacent_lines(t_draw *draw, int x, int y)
{
	if (x < draw->map->width - 1)
		draw_line_between_points(draw, x + 1, y);
	if (y < draw->map->height - 1)
		draw_line_between_points(draw, x, y + 1);
}

void	draw_wireframe(t_mlx *mlx)
{
	t_draw	draw;
	int		x;
	int		y;

	draw.mlx = mlx;
	draw.map = mlx->map;
	draw.color = 0x24F9DC;
	y = 0;
	while (y < draw.map->height)
	{
		x = 0;
		while (x < draw.map->width)
		{
			set_current_point(&draw, x, y, mlx);
			draw_adjacent_lines(&draw, x, y);
			x++;
		}
		y++;
	}
}
