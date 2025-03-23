#include "fdf.h"

#include <unistd.h>

static void	print_number(int num)
{
	char	buffer[12];
	int		len;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	len = 0;
	if (num == 0)
		buffer[len++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[len++] = (num % 10) + '0';
			num /= 10;
		}
	}
	int start = 0, end = len - 1;
	while (start < end)
	{
		char temp = buffer[start];
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

	if (!map || !map->matrix)
	{
		write(1, "Error: Mapa vacío o nulo.\n", 26);
		return;
	}

	// write(1, "Map dimensions: ", 16);
	// print_number(map->width);
	// write(1, "x", 1);
	// print_number(map->height);
	// write(1, "\n\n", 2);

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
