/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:13:18 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:34:12 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	update_line_position(t_line *line)
{
	int		e2;

	e2 = line->err;
	if (e2 > -line->dx)
	{
		line->err -= line->dy;
		line->start.x += line->sx;
	}
	if (e2 < line->dy)
	{
		line->err += line->dx;
		line->start.y += line->sy;
	}
}

int	get_total_steps(t_line *l)
{
	if (l->dx > l->dy)
		return (l->dx);
	else
		return (l->dy);
}

void	draw_line_step(t_mlx *mlx, t_line *line, int step, int total_steps)
{
	int		color;

	if (line->start.color == line->end.color)
		color = line->start.color;
	else
		color = get_step_color(line, step, total_steps);
	pixel_put(mlx, line->start.x, line->start.y, color);
}

void	draw_line_loop(t_mlx *mlx, t_line *line)
{
	int		total_steps;
	int		current_step;

	total_steps = get_total_steps(line);
	current_step = 0;
	while (line->start.x != line->end.x || line->start.y != line->end.y)
	{
		draw_line_step(mlx, line, current_step, total_steps);
		update_line_position(line);
		current_step++;
	}
}

void	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	line;

	line.start = start;
	line.end = end;
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
	pixel_put(mlx, line.end.x, line.end.y, end.color);
}
