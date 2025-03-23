/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:12 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/12 21:24:45 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	pos = 0;
	if (!s)
		return ;
	while (s[pos] && fd >= 0)
	{
		ft_putchar_fd(s[pos], fd);
		pos++;
	}
}
