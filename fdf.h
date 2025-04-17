/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:39:28 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/17 13:41:37 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> //perror
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
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
}	t_mlx;

t_map	*parse_file(char *filename);
void	free_map(t_map *map);
void	print_map(t_map *map); //borrar
void	process_map(char *filename);
void	render_map(t_map *map);
void	clear_image(t_img *img, int color, int width, int height);
void	create_image(t_mlx *mlx);
void	draw_line(t_img *img, t_point start, t_point end, int color, int width,
			int height);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color, int width,
			int height);
void	render_frame(t_mlx *mlx);
int		resize_handler(void *param);
int		esc_press(int keycode, void *param);
int		close_window(void *param);
int		mouse_wheel(int mousecode, void *param);

#endif