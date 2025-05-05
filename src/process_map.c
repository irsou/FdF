/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:25:26 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/24 18:25:26 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	process_map(char *filename)
{
	t_map	*map;

	map = read_map(filename);
	if (!map)
	{
		perror("File couldn't be read.");
		return ;
	}
	render_map(map);
	free_map(map);
}
