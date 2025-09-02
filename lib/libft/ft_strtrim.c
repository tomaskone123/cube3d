/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:31:14 by tomas             #+#    #+#             */
/*   Updated: 2024/06/07 17:12:37 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static bool	getset(char const s1, char const *set)
{
	while (*set)
	{
		if (*set == s1)
			return (true);
		set++;
	}
	return (false);
}

static size_t	getd(const char *s1, const char *set)
{
	int	d;

	d = 0;
	while (s1[d])
	{
		if (getset(s1[d], set) == true)
			d++;
		else
			return (d);
	}
	return (d);
}

static size_t	geti(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (getset(s1[i], set) == true)
			i--;
		else
			return (i);
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		d;
	int		len;
	char	*result;

	d = getd(s1, set);
	i = geti(s1, set);
	if (d > i)
		return (ft_strdup(""));
	len = i - d + 1;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	len = 0;
	while (s1[d] && d <= i)
	{
		result[len] = s1[d];
		len++;
		d++;
	}
	result[len] = '\0';
	return (result);
}

// int main(void)
// {
//     const char *s = "   xxx   xxx";
//     const char *c = " x";
//     char *r = ft_strtrim(s, c);
//     printf("%s\n", r);
// }
