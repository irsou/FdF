/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:39:09 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/26 10:07:44 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_map(t_map *map)
{
	int		pos;

	if (!map)
		return ;
	if (map->matrix)
	{
		pos = 0;
		while (pos < (map->height))
		{
			if (map->matrix[pos])
				free(map->matrix[pos]);
			pos++;
		}
		free(map->matrix);
	}
	free(map);
}
