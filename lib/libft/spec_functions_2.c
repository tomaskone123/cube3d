/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:36:55 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/20 15:52:03 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	print_low_hex(va_list arg)
{
	t_variables	v;

	v.remainder = 0;
	v.hex = malloc(17);
	if (!v.hex)
		return (-1);
	v.a = "0123456789abcdef";
	v.i = va_arg(arg, int);
	v.uni = (unsigned int)v.i;
	if (v.uni == 0)
	{
		ft_putchar_fd('0', 1);
		free(v.hex);
		return (1);
	}
	v.string = make_hex(0, v.uni, v.hex, v.a);
	v.result = reverse_string(v.hex, v.string);
	v.string = 0;
	while (v.result[v.string])
	{
		ft_putchar_fd(v.result[v.string], 1);
		v.string++;
	}
	free(v.hex);
	return (v.string);
}

int	print_upp_hex(va_list arg)
{
	t_variables	v;

	v.remainder = 0;
	v.hex = malloc(17);
	if (!v.hex)
		return (-1);
	v.a = "0123456789ABCDEF";
	v.i = va_arg(arg, int);
	v.uni = (unsigned int)v.i;
	if (v.uni == 0)
	{
		ft_putchar_fd('0', 1);
		free(v.hex);
		return (1);
	}
	v.string = make_hex(0, v.uni, v.hex, v.a);
	v.result = reverse_string(v.hex, v.string);
	v.string = 0;
	while (v.result[v.string])
	{
		ft_putchar_fd(v.result[v.string], 1);
		v.string++;
	}
	free(v.hex);
	return (v.string);
}

int	print_pointer(va_list arg)
{
	t_variables	v;

	v.a = "0123456789abcdef";
	v.ptr = va_arg(arg, void *);
	v.hex = malloc(17);
	if (!v.hex)
		return (-1);
	if (v.ptr == NULL)
	{
		write(1, "(nil)", 5);
		free(v.hex);
		return (5);
	}
	write(1, "0x", 2);
	v.lint = (unsigned long long)v.ptr;
	v.string = make_hex(0, v.lint, v.hex, v.a);
	v.result = reverse_string(v.hex, v.string);
	v.string = 0;
	while (v.result[v.string])
	{
		ft_putchar_fd(v.result[v.string], 1);
		v.string++;
	}
	free(v.hex);
	return (v.string + 2);
}
