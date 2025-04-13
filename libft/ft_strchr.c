/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:23:14 by marvin            #+#    #+#             */
/*   Updated: 2024/12/06 13:33:09 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		pos;

	if (s == NULL)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == (char)c)
			return ((char *)&s[pos]);
		pos++;
	}
	if ((char)c == '\0')
		return ((char *)&s[pos]);
	return (NULL);
}
/* Returns a pointer to the first occurrence of the character c in the string 
s.*/
