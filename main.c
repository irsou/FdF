/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:39:06 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/23 15:15:12 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		write(1, "Error: one argument expected.\n", 31);
		return (1);
	}
	map = parse_file(argv[1]);
	if (!map)
	{
		perror("File couldn't be read.");
		return (1);
	}
	print_map(map);
	//render_map(map);
	free_map(map);
}
