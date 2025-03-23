#include "fdf.h"

static void	print_number(int num)
{
	char buffer[50];
	int len = 0;
	int is_negative = 0;
	
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	
	if (num == 0)
		buffer[len++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[len++] = (num % 10) + '0';
			num /= 10;
		}
		if (is_negative)
			buffer[len++] = '-';
	}
	
	// Invertir el string
	int start = 0;
	int end = len - 1;
	char temp;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	
	write(1, buffer, len);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;
	
	// Imprimir dimensiones del mapa
	write(1, "Map dimensions: ", 16);
	print_number(map->width);
	write(1, "x", 1);
	print_number(map->height);
	write(1, "\n\n", 2);
	
	// Imprimir el mapa como una matriz de valores Z
	write(1, "Map contents (z values):\n", 25);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_number(map->matrix[i][j].z);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}