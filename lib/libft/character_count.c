/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:40:22 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/07 17:11:01 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	check_list(const char *format, va_list arg, t_convert f_list[],
		int string)
{
	t_variables	v;

	v.i = 0;
	v.function = 0;
	while (f_list[v.function].sym)
	{
		if (format[string + 1] == f_list[v.function].sym[0])
		{
			v.i += f_list[v.function].f(arg);
			return (v.i);
		}
		v.function++;
	}
	if (f_list[v.function].sym == NULL)
	{
		ft_putchar_fd(format[string + 1], 1);
		v.i++;
	}
	return (v.i);
}

int	character_count(const char *format, va_list arg, t_convert f_list[])
{
	t_variables	v;

	v.function = 0;
	v.string = 0;
	v.end_value = 0;
	v.i = 0;
	while (format[v.string])
	{
		if (format[v.string] == '%')
		{
			v.i += check_list(format, arg, f_list, v.string);
			v.string++;
		}
		else
		{
			ft_putchar_fd(format[v.string], 1);
			v.i++;
		}
		v.string++;
		v.function = 0;
	}
	return (v.i);
}
