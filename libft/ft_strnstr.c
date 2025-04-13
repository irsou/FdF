/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:51:58 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 14:02:46 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_position;
	size_t	l_position;

	b_position = 0;
	if (!*little)
		return ((char *)big);
	while (big[b_position] && b_position < len)
	{
		l_position = 0;
		while (big[b_position + l_position] == little[l_position]
			&& little[l_position] && b_position + l_position < len)
			l_position++;
		if (!little[l_position])
			return ((char *)&big[b_position]);
		b_position++;
	}
	return (0);
}
	/* The strnstr() function locates the first occurrence of the null-termi‐
     nated string little in the string big, where not more than len characters
     are searched.  Characters that appear after a ‘\0’ character are not
     searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.
	 If little is an empty string, big is returned; if little occurs nowhere
     in big, NULL is returned; otherwise a pointer to the first character of
     the first occurrence of little is returned
	 The following sets the pointer ptr to NULL, because only the first 4
     characters of largestring are searched:
           const char *largestring = "Foo Bar Baz";
           const char *smallstring = "Bar";
           char *ptr;

           ptr = strnstr(largestring, smallstring, 4)*/