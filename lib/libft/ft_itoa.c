/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:03:24 by tomas             #+#    #+#             */
/*   Updated: 2024/06/07 17:11:15 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	digit_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	signcheck(int n)
{
	int	i;

	if (n >= 0)
		i = 0;
	else
	{
		i = 1;
		n = -n;
	}
	return (i);
}

static void	itostr(int n, int len, int i, char *str)
{
	while (n && len >= i)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = digit_count(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = signcheck(n);
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	str[len] = '\0';
	len--;
	itostr(n, len, i, str);
	return (str);
}

// int main(void)
// {
// 	int c;
// 	char *s;
// 	// int	d;

// 	c = -6116451;
// 	s = ft_itoa(c);
// 	// d = digit_count(c);
// 	printf("%s\n", s);
// 	return (0);
// 	free(s);
// }
