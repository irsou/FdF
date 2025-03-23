/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:25:28 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 18:25:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_pos;
	size_t	end_pos;

	if (!s1 || !set)
		return (NULL);
	start_pos = 0;
	end_pos = ft_strlen(s1);
	while (s1[start_pos] != '\0' && ft_strchr(set, s1[start_pos]))
		start_pos++;
	while (end_pos > start_pos && ft_strchr(set, s1[end_pos - 1]))
		end_pos--;
	return (ft_substr(s1, start_pos, end_pos - start_pos));
}

/* Trims the characteres that are present in set from the beginning and end of 
s1. Returns the trimmed string allocated with malloc or NULL if memory
allocation fails */