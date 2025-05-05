/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:19:55 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 21:20:13 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_step_color(t_line *line, int step, int total_steps)
{
	if (step < total_steps / 2)
		return (line->start.color);
	else
		return (line->end.color);
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= mlx->win_width || y >= mlx->win_height)
		return ;
	dst = mlx->img.addr + (y * mlx->img.line_length + x
			*(mlx->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
