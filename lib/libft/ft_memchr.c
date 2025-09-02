/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:09:03 by tomas             #+#    #+#             */
/*   Updated: 2024/06/06 13:42:23 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ps;
	unsigned char	value;

	i = 0;
	ps = (unsigned char *)s;
	value = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == value)
			return ((void *)ps + i);
		i++;
	}
	return (NULL);
}
