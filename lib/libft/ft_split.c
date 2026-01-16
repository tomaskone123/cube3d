/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuik <skuik@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:15:48 by tomas             #+#    #+#             */
/*   Updated: 2026/01/16 15:00:27 by skuik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

size_t	ft_wordcount(char const *s, char c)
{
	size_t	word;

	if (!s)
		return (0);
	word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word++;
			while (*s != c && *s)
				s++;
		}
	}
	return (word + 1);
}

size_t	ft_wordlen(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	int		len;
	char	**str;

	i = 0;
	j = -1;
	word = ft_wordcount(s, c);
	str = ft_calloc(word, sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++j < word - 1)
	{
		while (s[i] == c)
			i++;
		len = ft_wordlen(s, c, i);
		str[j] = ft_substr(s, i, len);
		i += len;
	}
	str[j] = NULL;
	return (str);
}
