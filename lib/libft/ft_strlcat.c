/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:35:16 by tomas             #+#    #+#             */
/*   Updated: 2024/08/08 12:19:20 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	comb;
	size_t	dst_len;
	size_t	cop_len;
	size_t	src_len;

	if (size > ft_strlen(dst))
		dst_len = ft_strlen(dst);
	else
		dst_len = size;
	src_len = ft_strlen(src);
	comb = dst_len + src_len;
	if (dst_len == size)
		return (comb);
	cop_len = size - dst_len - 1;
	if (cop_len > src_len)
		cop_len = src_len;
	ft_memcpy(dst + dst_len, src, cop_len);
	dst[dst_len + cop_len] = '\0';
	return (comb);
}
