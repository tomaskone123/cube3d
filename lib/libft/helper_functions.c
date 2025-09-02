/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:25:07 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/07 17:03:26 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

char	*reverse_string(char *hex, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = hex[start];
		hex[start] = hex[end];
		hex[end] = temp;
		start++;
		end--;
	}
	return (hex);
}

int	make_hex(int string, unsigned long long lint, char *hex, const char *a)
{
	if (lint == 0)
	{
		hex[string++] = '0';
	}
	else
	{
		while (lint > 0)
		{
			hex[string++] = a[lint % 16];
			lint /= 16;
		}
	}
	hex[string] = '\0';
	return (string);
}

char	*ft_utoa(unsigned int num)
{
	unsigned int	temp;
	int				num_digits;
	char			*str;

	temp = num;
	num_digits = 0;
	if (temp == 0)
		num_digits = 1;
	else
	{
		while (temp != 0 && ++num_digits)
			temp /= 10;
	}
	str = (char *)malloc((num_digits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[num_digits] = '\0';
	while (num_digits--)
	{
		str[num_digits] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
