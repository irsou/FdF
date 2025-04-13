/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:39:45 by marvin            #+#    #+#             */
/*   Updated: 2024/12/06 19:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *ptr)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = (result * 10) + (*ptr - '0');
		ptr++;
	}
	return (sign * result);
}

/* Converts the initial portion of the string pointed to by nptr to int.
	- Ignores: spaces, tabs, newline break...
	- Stops after a non-numeric char
	- String migth start by + / - char
	- Returns 0 for empty string or containing only non-numeric chars
*/