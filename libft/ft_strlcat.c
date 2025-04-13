/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:19:54 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/02 19:59:29 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	dest_pos;
	size_t	src_pos;

	dest_len = 0;
	src_len = ft_strlen(src);
	src_pos = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	if (dest_len >= size)
		return (size + src_len);
	dest_pos = dest_len;
	while (src[src_pos] != '\0' && dest_pos < (size - 1))
	{
		dest[dest_pos] = src[src_pos];
		src_pos++;
		dest_pos++;
	}
	if (dest_pos < size)
		dest[dest_pos] = '\0';
	return (dest_len + src_len);
}

/* Concatenates strings safer than strncat. Takes the full size of the buffer
and guarantees to NUL-terminate the result (as long as size is larger than 0).
- A byte for the NUL should be included in size. 
- Both src and dst must be NUL-terminated.*/