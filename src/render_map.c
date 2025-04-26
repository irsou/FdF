/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:23:19 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/26 10:07:44 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	iso_convert(t_point p, t_mlx *mlx)
{
	t_point	iso;
	int		offset_x;
	int		offset_y;

	offset_x = mlx->win_width / 2;
	offset_y = mlx->win_height / 4;
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

void	draw_wireframe(t_mlx *mlx)
{
	int		x;
	int		y;
	t_draw	draw;

	draw.mlx = mlx;
	draw.map = mlx->map;
	draw.color = 0x24F9DC;
	y = 0;
	while (y < draw.map->height)
	{
		x = 0;
		while (x < draw.map->width)
		{
			draw.current.x = x;
			draw.current.y = y;
			draw.current.z = draw.map->matrix[y][x].z;
			draw.current.color = draw.map->matrix[y][x].color;
			draw.current = iso_convert(draw.current, mlx);
			my_mlx_pixel_put(mlx, draw.current.x, draw.current.y, draw.current.color);
			if (x < draw.map->width - 1)
				draw_line_between_points(&draw, x + 1, y);
			if (y < draw.map->height - 1)
				draw_line_between_points(&draw, x, y + 1);
			x++;
		}
		y++;
	}
}

void	render_frame(t_mlx *mlx)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	create_image(mlx);
	if (!mlx->img.img_ptr)
	{
		perror("Error al crear la imagen");
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		return ;
	}
	draw_wireframe(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}

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
	mlx.win_width = 1500;
	mlx.win_height = 1100;
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

void	render_map(t_map *map)
{
	static t_mlx	*mlx;

	mlx = init_mlx(map);
	if (!mlx)
		return ;
	render_frame(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, esc_press, mlx);
	mlx_hook(mlx->win_ptr, 22, 1L << 17, resize_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_wheel, mlx);
	mlx_loop(mlx->mlx_ptr);
}

/*void	render_map(t_map *map)
{
	static t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
	{
		perror("Error de MLX");
		return ;
	}
	mlx.scale = 20;
	mlx.win_width = 1500;
	mlx.win_height = 1100;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_width, mlx.win_height,
			"FdF");
	if (!mlx.win_ptr)
	{
		perror("Error de ventana MLX");
		mlx_destroy_display(mlx.mlx_ptr);
		return ;
	}
	mlx.map = map;
	mlx.img.img_ptr = NULL;
	render_frame(&mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, esc_press, &mlx);
	mlx_hook(mlx.win_ptr, 22, 1L << 17, resize_handler, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_wheel, &mlx);
	mlx_loop(mlx.mlx_ptr);
}*/
