#include "fdf.h"

char	*free_map(t_map *map)
{
	free(map);
	return (NULL);
}
t_map	*parse_file(char *filename)
{
	t_map	*map;
	int		fd;
	int		pos;
	char	*line;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	//map->heigth = calc_height(filename);
	fd = open(filename, 0);
	if (fd < 0)
		return (free_map(map));
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (free_map(map));
	}
	//map->width = calc_width(line);
	map->matrix = (t_point **)malloc(sizeof(t_point *)*map->heigth);
	if (!map->matrix)
		return (free_map(map));
	pos = 0;
	while (pos < (map->heigth))
	{
		map->matrix[pos] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->matrix[pos])
		{
			while (pos >0)
				free(map->matrix[--pos]);
			free(map->matrix);
			free(map);
			return (NULL);
		}
		pos++;
	}
	fd = open(filename, 0);
	if (fd < 0)
		return (free_map(map));
	//fill_points(map, fd);
	close(fd);
	return (map);
}