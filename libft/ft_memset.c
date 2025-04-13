/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:08:37 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/02 19:05:20 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t length)
{
	size_t			pos;
	unsigned char	*dir;

	pos = 0;
	dir = ptr;
	while (pos < length)
	{
		dir[pos] = (unsigned char)value;
		pos++;
	}
	return (dir);
}
/* Fills the first n (length) bytes of the memory area pointed to by str with
the constant byte (value)*/