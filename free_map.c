#include "fdf.h"

void	free_map(t_map *map)
{
	int		pos;
	if (!map)
		return ;
	if (map->matrix)
	{
		pos = 0;

		while (pos < (map->heigth))
		{
			if (map->matrix[pos])
				free(map->matrix[pos]);
			pos++;
		}
		free(map->matrix);
	}
	free(map);
}