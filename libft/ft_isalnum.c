/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:48:41 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 13:25:43 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int s)
{
	if (ft_isalpha(s) || ft_isdigit(s))
		return (1);
	return (0);
}
/* Checks for an alphabetic character. If it.It's equivalent to 
ft_isalpha(s) || ft_isdigit(s)*/