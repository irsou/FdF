/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:40:04 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 16:40:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	new_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	new_len = ft_strlen(s1) + ft_strlen (s2);
	new_str = (char *)malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s1, ft_strlen(s1));
	ft_memmove(new_str + ft_strlen(s1), s2, ft_strlen(s2));
	new_str[new_len] = '\0';
	return (new_str);
}

/* Returns a new string after concatinating s1 and s2. 
Returns null if memory allocation fails. */
