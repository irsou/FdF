/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:31:42 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/18 12:31:42 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_hex_to_int(char *hex)
{
	int		value;

	value = 0;
	if (*hex == '0' && (*(hex + 1) == 'x' || *(hex + 1) == 'X'))
		hex += 2;
	while ((*hex >= '0' && *hex <= '9') || (*hex >= 'a' && *hex <= 'f')
		|| (*hex >= 'A' && *hex <= 'F'))
	{
		value = value * 16;
		if (*hex >= '0' && *hex <= '9')
			value += *hex - '0';
		else if (*hex >= 'a' && *hex <= 'f')
			value += *hex - 'a' + 10;
		else if (*hex >= 'A' && *hex <= 'F')
			value += *hex - 'A' + 10;
		hex++;
	}
	return (value);
}
