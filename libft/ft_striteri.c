/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:22:20 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/14 10:09:43 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	pos;

	if (!s || !f)
		return ;
	pos = 0;
	while (s[pos] != '\0')
	{
		f(pos, &s[pos]);
		pos++;
	}
}
