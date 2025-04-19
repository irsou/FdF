/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:23:19 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/19 12:09:38 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (0);
}

int	esc_press(int keycode, void *param)
{
	t_mlx	*mlx;

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

int	resize_handler(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	render_frame(mlx);
	return (0);
}

int	mouse_wheel(int mousecode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx)
    {
        printf("Error: mlx es NULL\n");
        return (0);
    }
	if (mousecode == 4)
	{
		printf("mouse up\n");
		printf("%d\n", mlx->scale);
		mlx->scale += 1;
		printf("%d\n", mlx->scale);
		render_frame(mlx);

	}
	if (mousecode == 5)
	{
		printf("mouse down\n");
	}
	return (0);
	}

	int	mouse_up(void *param)
	{
		t_mlx	*mlx;
		
		mlx = (t_mlx *)param;
		if (!mlx)
		{
			printf("Error: mlx es NULL\n");
			return (0);
		}
		if (!mlx->scale)
		{
			printf("Error: mlx.scale es NULL\n");
			return (0);
		}
		else 
		{
			mlx->scale += 1;
			render_frame(mlx);
		}
		return (0);
	}

	int	mouse_down(void *param)
	{
		t_mlx	*mlx;
		
		mlx = (t_mlx *)param;
		if (!mlx)
		{
			printf("Error: mlx es NULL\n");
			return (0);
		}
		if (!mlx->scale)
		{
			printf("Error: mlx.scale es NULL\n");
			return (0);
		}
		else 
		{
			mlx->scale -= 1;
			render_frame(mlx);
		}
		return (0);
	}
