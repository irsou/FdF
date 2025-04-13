/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:00:49 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 10:23:30 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int s)
{
	if (s >= 32 && s <= 126)
		return (1);
	return (0);
}
/* Returns 0 if the received char is not a printable character (including 
space) and a different number otherwise */