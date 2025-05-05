/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_map_view.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:10:36 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:51:35 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	count_elements(char *line)
{
	int		width;
	int		pos;

	width = 0;
	pos = 0;
	while (line[pos])
	{
		while (line[pos] == ' ')
			pos++;
		if (line[pos] != '\0' && line[pos] != '\n')
		{
			width++;
			while (line[pos] && line[pos] != ' ' && line[pos] != '\n')
				pos++;
		}
		else
			break ;
	}
	return (width);
}

static int	calc_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, 0);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		return (0);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("height: %d\n", height);
	return (height);
}

static int	calc_width(char *filename)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(filename, 0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	width = count_elements(line);
	free(line);
	close(fd);
	return (width);
}

t_map	*get_initial_map_view(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height(filename);
	map->width = calc_width(filename);
	if (map->height == 0 || map->width == 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}
