/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:15:53 by tomas             #+#    #+#             */
/*   Updated: 2024/06/05 14:45:10 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*temp;

	total = ft_strlen(s1) + ft_strlen(s2);
	temp = malloc((total + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	temp -= total;
	return (temp);
}

// int main(void)
// {
// 	const char *a = "tripouille";
// 	const char *b = "42";
// 	char *n;

// 	n = ft_strjoin(a, b);
// 	int d = strncmp(n, "tripouille42", -1);
// 	printf("%s\n%d\n", n, d);
// }
