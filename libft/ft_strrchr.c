/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:50:22 by marvin            #+#    #+#             */
/*   Updated: 2024/12/06 13:33:21 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;
	char	*ptr;

	pos = 0;
	ptr = NULL;
	while (s[pos] != '\0')
	{
		if (s[pos] == (char)c)
			ptr = (char *)&s[pos];
		pos++;
	}
	if ((char)c == '\0')
		return ((char *)&s[pos]);
	return (ptr);
}

/* Returns a pointer to the last occurrence of the character c in the string
 s */