/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:40:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/07 09:40:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}
/*Allocates memory for an array of nmemb elements of size bytes each and 
returns a pointer to the allocated memory.  The memory is set to zero. 
 	- If nmemb or size is 0, returns a unique pointer value that can be 
	successfully passed to free().
	- If  nmemb * size would result in integer overflow, then calloc() 
	returns an error.  By contrast, an integer overflow would not be 
	detected in the following call to malloc(), with the result that an 
	incorrectly sized block of memory would be allocated:
		malloc(nmemb * size); 
 */