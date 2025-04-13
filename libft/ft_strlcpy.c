/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 10:33:09 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 09:11:33 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;
	size_t	pos;

	src_len = ft_strlen(src);
	pos = 0;
	if (dest_size == 0)
		return (src_len);
	while (pos < (dest_size - 1) && src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (src_len);
}

/* Copies up to (size - 1) characters from the NUL-terminated string src 
 to dst.
- safer than strncpy ( NUL-terminates the result as long as size is
larger than 0)
- a byte for the NUL should be included in size. 
- src must be NUL-terminated. */