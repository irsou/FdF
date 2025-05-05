/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:16:25 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:37:10 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	process_point(t_map *map, int x, int y, char *segment)
{
	map->matrix[x][y].x = y;
	map->matrix[x][y].y = x;
	map->matrix[x][y].z = ft_atoi(segment);
	map->matrix[x][y].color = get_color(segment);
}

void	fill_empty_point(t_map *map, int x, int y)
{
	map->matrix[x][y].x = y;
	map->matrix[x][y].y = x;
	map->matrix[x][y].z = 0;
	map->matrix[x][y].color = 0x24F9DC;
}

void	handle_extra_elements(int *warning)
{
	if (!(*warning))
	{
		write(2,
			"Line has more elements than expected. Extra elements ignored.\n",
			63);
		*warning = 1;
	}
}
