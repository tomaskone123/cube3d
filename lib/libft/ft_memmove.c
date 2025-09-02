/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:07:27 by tomas             #+#    #+#             */
/*   Updated: 2024/06/07 17:11:28 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	cpysrc(char *pdest, char *psrc, size_t i, size_t n)
{
	if (pdest > psrc)
	{
		while (n != 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	i = 0;
	cpysrc(pdest, psrc, i, n);
	return (pdest);
}

// int main(void)
// {
//    	const char src[]  = "123456789";
// 	char *dest= (char *)src + 1;

//    	printf("Before memmove dest = %s, src = %s\n", dest, src);
//    	memmove(dest, src, 7);
//    	printf("After memmove dest = %s, src = %s\n\n", dest, src);

// 	const char src2[]  = "123456789";
// 	char *dest2= (char *)src2 + 1;

//    	printf("Before ft_memmove dest2 = %s, src2 = %s\n", dest2, src2);
//    	ft_memmove(dest2, src2, 7);
//    	printf("After ft_memmove dest2 = %s, src2 = %s\n\n", dest2, src2);

//    	return(0);
// }
