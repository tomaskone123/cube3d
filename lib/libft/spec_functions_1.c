/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:25:02 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/07 17:03:35 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_string(va_list arg)
{
	t_variables	v;

	v.i = 0;
	v.chartotal = 0;
	v.result = va_arg(arg, char *);
	if (v.result == NULL)
		return (write(1, "(null)", 6));
	v.chartotal = ft_strlen(v.result);
	ft_putstr_fd(v.result, 1);
	return (v.chartotal);
}

int	print_char(va_list arg)
{
	t_variables	v;

	v.b = va_arg(arg, int);
	ft_putchar_fd(v.b, 1);
	return (1);
}

int	print_int(va_list arg)
{
	t_variables	v;
	char		*str;

	v.b = va_arg(arg, int);
	str = ft_itoa(v.b);
	v.chartotal = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (v.chartotal);
}

int	print_unsigned(va_list arg)
{
	t_variables	v;
	char		*str;

	v.uni = va_arg(arg, unsigned int);
	str = ft_utoa(v.uni);
	v.chartotal = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (v.chartotal);
}
