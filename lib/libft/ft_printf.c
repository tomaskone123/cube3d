/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:33 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/07 17:04:08 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	t_variables	v;
	va_list		arg;
	t_convert	f_list[9];

	f_list[0] = (t_convert){"c", print_char};
	f_list[1] = (t_convert){"s", print_string};
	f_list[2] = (t_convert){"d", print_int};
	f_list[3] = (t_convert){"i", print_int};
	f_list[4] = (t_convert){"u", print_unsigned};
	f_list[5] = (t_convert){"p", print_pointer};
	f_list[6] = (t_convert){"x", print_low_hex};
	f_list[7] = (t_convert){"X", print_upp_hex};
	f_list[8] = (t_convert){NULL, NULL};
	v.i = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	v.i = character_count(format, arg, f_list);
	va_end(arg);
	return (v.i);
}

// int	main(void)
// {
// 	char			c = 'h';
// 	char			*s = "hello";
// 	int				d = 123;
// 	int				i = 456;
// 	unsigned int	u = -123;
// 	int				x = -1234;
// 	int				X = -1234;

// 	ft_printf(" aa%caa aa%saa aa%paa aa%daa aa%iaa aa%uaa aa%xaa aa%Xaa
//  aa%%aa\n",
// c, s, &s, d, i, u, x, X);
// 	printf(" aa%caa aa%saa aa%paa aa%daa aa%iaa aa%uaa aa%xaa aa%Xaa
// aa%%aa\n",
// c, s, &s, d, i, u, x, X);
// 	ft_printf("%%%%%u\n", u);
// 	printf("%%%%%u\n", u);
// 	ft_printf("%%%%%s\n", s);
// 	printf("%%%%%s\n", s);
// 	ft_printf("%%%p%%\n", &u);
// 	printf("%%%p%%\n", &u);

// }

// #include "ft_printf.h"
// #include "libft/libft.h"
// #include <stdio.h>
// // Include your ft_printf header

// int main(void) {
//     // Test case for %c
//     printf("ft_printf: %d\n", ft_printf("Character: %c\n", 'A'));
//     printf("printf: %d\n", printf("Character: %c\n", 'A'));

//     // Test case for %s
//     printf("ft_printf: %d\n", ft_printf("String: %s\n", "Hello, World!"));
//     printf("printf: %d\n", printf("String: %s\n", "Hello, World!"));

//     // Test case for %p
//     int x = 42;
//     printf("ft_printf: %d\n", ft_printf("Pointer: %p\n", &x));
//     printf("printf: %d\n", printf("Pointer: %p\n", &x));

//     // Test case for %d
//     printf("ft_printf: %d\n", ft_printf("Decimal: %d\n", 1234));
//     printf("printf: %d\n", printf("Decimal: %d\n", 1234));

//     // Test case for %i
//     printf("ft_printf: %d\n", ft_printf("Integer: %i\n", -1234));
//     printf("printf: %d\n", printf("Integer: %i\n", -1234));

//     // Test case for %u
//     printf("ft_printf: %d\n", ft_printf("Unsigned: %u\n", 4294967295U));
//     printf("printf: %d\n", printf("Unsigned: %u\n", 4294967295U));

//     // Test case for %x
//     printf("ft_printf: %d\n", ft_printf("Hexadecimal (lowercase): %x\n",
// 0xabcdef));
//     printf("printf: %d\n", printf("Hexadecimal (lowercase): %x\n",
// 0xabcdef));

//     // Test case for %X
//     printf("ft_printf: %d\n", ft_printf("Hexadecimal (uppercase): %X\n",
// 0xABCDEF));
//     printf("printf: %d\n", printf("Hexadecimal (uppercase): %X\n",
// 0xABCDEF));

//     // Test case for %%
//     printf("ft_printf: %d\n", ft_printf("Percent sign: %%\n"));
//     printf("printf: %d\n", printf("Percent sign: %%\n"));

//     return (0);
// }
