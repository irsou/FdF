/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:10:32 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:15:25 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_matrix(t_map *map)
{
	int		pos;

	pos = 0;
	while (pos < map->height)
	{
		free(map->matrix[pos]);
		pos++;
	}
	free(map->matrix);
	free(map);
}

int	allocate_map_matrix(t_map *map)
{
	int	pos;

	map->matrix = malloc(sizeof(t_point *) * map->height);
	if (!map->matrix)
	{
		free(map);
		return (0);
	}
	pos = 0;
	while (pos < map->height)
	{
		map->matrix[pos] = malloc(sizeof(t_point) * map->width);
		if (!map->matrix[pos])
		{
			free_matrix(map);
			return (0);
		}
		pos++;
	}
	return (1);
}
