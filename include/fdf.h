/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:39:28 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/02 22:13:05 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> //perror
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**matrix;
	int		width;
	int		height;
}	t_map;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_img		img;
	int			win_width;
	int			win_height;
	float		scale;
	int			offset_x_step;
	int			offset_y_step;
}	t_mlx;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	int		color;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}	t_line;

typedef struct s_draw
{
	t_mlx	*mlx;
	t_map	*map;
	t_point	current;
	int		color;
}	t_draw;

typedef struct s_fill_points_pos
{
	int		x;
	int		y;
	int		z;
}	t_fill_points_pos;

t_map	*parse_file(char *filename);
void	free_map(t_map *map);
void	print_map(t_map *map); //borrar
void	process_map(char *filename);
void	render_map(t_map *map);
void	create_image(t_mlx *mlx);
void	draw_line(t_mlx *mlx, t_point start, t_point end);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	render_frame(t_mlx *mlx);
int		resize_handler(void *param);
int		close_window(void *param);
int		mouse_wheel(int button, int x, int y, void *param);
int		ft_hex_to_int(char *hex);
int		key_press(int keycode, void *param);

#endif