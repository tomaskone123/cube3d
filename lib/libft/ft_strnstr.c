/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:21:50 by tomas             #+#    #+#             */
/*   Updated: 2024/06/07 17:12:15 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	checknext(const char *big, const char *little, size_t i, size_t l)
{
	int	match;

	match = 1;
	if (big[i + l] != little[l])
		match = 0;
	return (match);
}

static int	nomatch(int match, size_t l)
{
	if (match == 0)
		l = 0;
	return (l);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	int		match;

	l = 0;
	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (little[0] == big[i])
		{
			match = 1;
			while (little[l] != '\0' && i + l < len)
			{
				match = checknext(big, little, i, l);
				l++;
			}
			l = nomatch(match, l);
			if (little[l] == '\0' && match)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char heystack[30] = "aaabcabcd";
// 	// char needle[10] = "aabc";
// 	// char * empty = (char*)"";
// 	char *s1 = ft_strnstr(heystack, "abcd", 9);
// 	// int s2 = strnstr(heystack, needle, -1);
// 	char *s3 = ft_strnstr(heystack, "cd", 8);
// 	// int s4 = strnstr(heystack, "abcd", 9);
// 	printf("%s\n%s\n", s1,s3);
// }
