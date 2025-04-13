/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:24:57 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 13:28:33 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			position;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	position = 0;
	while (position < n)
	{
		if (ptr[position] == (unsigned char)c)
			return ((void *)ptr + position);
		position++;
	}
	return (NULL);
}

/* scans the initial n bytes of the memory area pointed to by s for the first 
instance of c.
Both c and the bytes of the memory area pointed to by s are interpreted as 
unsigned char.*/