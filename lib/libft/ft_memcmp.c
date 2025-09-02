/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:45:50 by tomas             #+#    #+#             */
/*   Updated: 2024/06/05 14:43:41 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (int)n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	/* 1 */printf("1.%d\n", ft_memcmp(s, sCpy, 4));
// 	/* 2 */printf("2.%d\n", ft_memcmp(s, s2, 0));
// 	/* 3 */printf("3.%d\n", ft_memcmp(s, s2, 1));
// 	/* 4 */printf("4.%d\n", ft_memcmp(s2, s, 1));
// 	/* 5 */printf("5.%d\n", ft_memcmp(s2, s3, 4));
// 	printf("\n");
// 	/* 1 */printf("1.%d\n", memcmp(s, sCpy, 4));
// 	/* 2 */printf("2.%d\n", memcmp(s, s2, 0));
// 	/* 3 */printf("3.%d\n", memcmp(s, s2, 1));
// 	/* 4 */printf("4.%d\n", memcmp(s2, s, 1));
// 	/* 5 */printf("5.%d\n", memcmp(s2, s3, 4));
// }
