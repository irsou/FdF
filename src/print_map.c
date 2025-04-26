/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:49:41 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/21 12:09:51 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <unistd.h>

/*static void	print_number(int num)
{
	char	buffer[12];
	int		len;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
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
}*/

// static int	fill_buffer(int num, char *buffer)
// {
// 	int		len;

// 	len = 0;
// 	if (num == 0)
// 		buffer[len++] = '0';
// 	else
// 	{
// 		while (num > 0)
// 		{
// 			buffer[len++] = (num % 10) + '0';
// 			num /= 10;
// 		}
// 	}
// 	return (len);
// }

// static void	reverse_and_write(char *buffer, int len)
// {
// 	int		start;
// 	int		end;
// 	char	tmp;

// 	start = 0;
// 	end = len - 1;
// 	while (start < end)
// 	{
// 		tmp = buffer[start];
// 		buffer[start] = buffer[end];
// 		buffer[end] = tmp;
// 		start++;
// 		end--;
// 	}
// 	write(1, buffer, len);
// }

// static void	print_number(int num)
// {
// 	char	buffer[12];
// 	int		len;

// 	if (num == -2147483648)
// 		return (write(1, "-2147483648", 11), (void)0);
// 	if (num < 0)
// 	{
// 		write(1, "-", 1);
// 		num = -num;
// 	}
// 	len = fill_buffer(num, buffer);
// 	reverse_and_write(buffer, len);
// }

// void	print_map(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	if (!map || !map->matrix)
// 	{
// 		write(1, "Error: Mapa vacío o nulo.\n", 26);
// 		return ;
// 	}
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			print_number(map->matrix[i][j].z);
// 			write(1, " ", 1);
// 			j++;
// 		}
// 		write(1, "\n", 1);
// 		i++;
// 	}
// }

void	print_map(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->matrix)
	{
		write(1, "Error: Mapa vacío o nulo.\n", 26);
		return ;
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%d(0x%06X) ", map->matrix[i][j].z, map->matrix[i][j].color);
			j++;
		}
		printf("\n");
		i++;
	}
}
