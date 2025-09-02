/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:09:36 by tomas             #+#    #+#             */
/*   Updated: 2024/06/06 13:53:43 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ps;
	int			i;
	char		cc;

	cc = c;
	i = 0;
	ps = s;
	if (cc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == cc)
			i++;
		s++;
	}
	while (i > 0)
	{
		if ((*ps == cc) && (i > 0))
			--i;
		if (i == 0)
			return ((char *)ps);
		ps++;
	}
	return (NULL);
}
