/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:38:57 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:09:19 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void	*free_and_return(t_map *map)
// {
// 	free(map);
// 	return (NULL);
// }

t_map	*read_map(char *filename)
{
	t_map	*map;

	map = get_initial_map_view(filename);
	if (!map)
		return (NULL);
	if (!allocate_map_matrix(map))
		return (NULL);
	if (!fill_matrix(map, filename))
	{
		free_matrix(map);
		return (NULL);
	}
	return (map);
}
