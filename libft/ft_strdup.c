/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:33:29 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 15:33:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ptr;

	size = ft_strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, size);
	ptr[size] = '\0';
	return (ptr);
}

/*Returns a pointer to a new string which is a duplicate of the string s. Memory
for the new string is obtained with malloc(3), and can be freed with free(3).
 It returns NULL if insufficient memory was available, with errno set to 
 indicate the error*/