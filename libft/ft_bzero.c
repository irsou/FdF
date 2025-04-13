/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:24:55 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/06 09:34:20 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	ft_memset(ptr, 0, len);
}
/* erases the data in the n bytes of the memory starting at the location 
pointed to by s, by writing zeros (bytes containing '\0') to that area*/
