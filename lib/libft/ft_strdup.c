/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:11:55 by tomas             #+#    #+#             */
/*   Updated: 2024/06/06 14:55:04 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*new;
	char	*cnew;

	new = malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (new == NULL)
		return (NULL);
	cnew = new;
	while (*s)
	{
		*new = *s;
		new ++;
		s++;
	}
	*new = '\0';
	return (cnew);
}

// int main(void)
// {
// 	const char *s = "Hello world";
// 	char *d = ft_strdup(s);

// 	printf("%s\n", d);
// 	return (0);
// }
