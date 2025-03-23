/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:12:35 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 19:53:10 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t		position;

	position = 0;
	while (position < n)
	{
		if (str[position] == '\0' || str2[position] == '\0')
			return ((unsigned char)str[position]
				- (unsigned char)str2[position]);
		if (str[position] != str2[position])
			return ((unsigned char)str[position]
				-(unsigned char)str2[position]);
		position++;
	}
	return (0);
}
/*  Compares the the first (at most) n bytes of two strings, s1 and s2. 
Returns an integer:
- 0, if the s1 and s2 are equal;
- a negative value if s1 is less than s2;
- a positive value if s1 is greater than s2. function is similar, except it 
compares only*/
