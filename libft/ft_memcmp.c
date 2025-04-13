/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:59:04 by marvin            #+#    #+#             */
/*   Updated: 2024/12/06 13:34:53 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				position;

	p1 = (const unsigned char *)ptr1;
	p2 = (const unsigned char *)ptr2;
	position = 0;
	while (position < num)
	{
		if (p1[position] != p2[position])
			return (p1[position] - p2[position]);
		position++;
	}
	return (0);
}

/* compares the first n bytes (each interpreted as unsigned char) of the memory 
areas s1 and s2*/