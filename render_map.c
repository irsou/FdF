/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:17:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/13 19:11:15 by isousa-s         ###   ########.fr       */
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

int esc_press(int keycode, void *param)
{
	t_mlx *mlx;
	
	mlx = (t_mlx *)param;
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(0);
	}
	return (0);
}

int resize_handler(void *param)
{
	t_mlx *mlx = (t_mlx *)param;

	render_frame(mlx);
	return (0);
}

t_point iso_convert(t_point p, t_mlx *mlx)
{
	t_point iso;
	int		scale;
	int		offset_x;
	int		offset_y;

	scale = 20;
	offset_x = mlx->win_width / 2;
	offset_y = mlx->win_height / 4;
	iso.x = (p.x - p.y) * cos(0.523599) * scale;
	iso.y = (p.x + p.y) * sin(0.523599) * scale - p.z * scale / 2;
	iso.z = p.z;
	iso.x += offset_x;
	iso.y += offset_y;
	return iso;
}

void draw_wireframe(t_mlx *mlx) {
	int x;
	int y;
	t_point current, next, down;
	t_map *map;
	map = mlx->map;
	y = 0;
	printf("Dimensiones del mapa: %d x %d\n", map->width, map->height);
	while (y < map->height) {
		x = 0;
		while (x < map->width) {
			current.x = x;
			current.y = y;
			current.z = map->matrix[y][x].z;
			current = iso_convert(current, mlx);
			my_mlx_pixel_put(&mlx->img, current.x, current.y, 0xFF0000, mlx->win_width, mlx->win_height);
			if (x < map->width - 1) {
				next.x = x + 1;
				next.y = y;
				next.z = map->matrix[y][x + 1].z;
				next = iso_convert(next, mlx);
				draw_line(&mlx->img, current, next, 0xFFFFFF, mlx->win_width, mlx->win_height);
			}
			if (y < map->height - 1) {
				down.x = x;
				down.y = y + 1;
				down.z = map->matrix[y + 1][x].z;
				down = iso_convert(down, mlx);
				draw_line(&mlx->img, current, down, 0xFFFFFF, mlx->win_width, mlx->win_height);
			}
			x++;
		}
		y++;
	}
}

void draw_debug_map(t_mlx *mlx)
{
	t_map *map;
	int scale = 20;
	int start_x = 100;
	int start_y = 100;
	int x;
	int y;
	int color;

	map = mlx->map;
	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			int px = start_x + x * scale;
			int py = start_y + y * scale;
			if (x == map->width - 1 || y == map->height - 1)
				color = 0xFF0000;
			else
				color = 0xFFFFFF;
			my_mlx_pixel_put(&mlx->img, px, py, color, mlx->win_width, mlx->win_height);
			x++;
		}
		y++;
	}
}

void    render_frame(t_mlx *mlx)
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

void render_map(t_map *map)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
		mlx.win_width = 800;
	mlx.win_height = 600;
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "FdF");
	if (!mlx.mlx_ptr)
    {
		perror("Error de MLX");
		return ;
	}
	if (!mlx.win_ptr)
	{
		perror("Error de ventana MLX");
		mlx_destroy_display(mlx.mlx_ptr);
		free(mlx.mlx_ptr);
		return ;
	}
	mlx.map = map;
	mlx.img.img_ptr = NULL;
	render_frame(&mlx);
	mlx_hook(mlx.win_ptr, 2, 1L<<0, esc_press, &mlx);
	mlx_hook(mlx.win_ptr, 22, 1L << 17, resize_handler, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
