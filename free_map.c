/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:39:09 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/23 10:05:28 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
