/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:34:32 by isousa-s          #+#    #+#             */
/*   Updated: 2024/12/11 21:03:44 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_length(int num)
{
	size_t	len;

	len = 1;
	if (num < 0)
	{
		if (num == INT_MIN)
		{
			len++;
			num = - (num / 10);
		}
		else
			num = -num;
		len++;
	}
	while ((num / 10) > 0)
	{
		len ++;
		num = num / 10;
	}
	return (len);
}

static char	*get_string(int n, char *string, size_t len)
{
	size_t	pos;

	pos = len - 1;
	string[len] = '\0';
	if (n == 0)
		string[0] = '0';
	else if (n == INT_MIN)
	{
		ft_strlcpy(string, "-2147483648", len + 1);
		return (string);
	}
	if (n < 0)
	{
		n = -n;
		string[0] = '-';
	}
	while (n != 0)
	{
		string[pos--] = (n % 10) + '0';
		n = n / 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	len;

	len = get_number_length(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	return (get_string(n, string, len));
}
