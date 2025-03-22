#ifndef FDF_H
# define FDF_H

#include <stdio.h> //perror
#include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct s_map
{
	t_point **matrix;
	int width;
	int heigth;
} t_map;

t_map	*parse_file(char *filename);
void	free_map(t_map *map);

#endif