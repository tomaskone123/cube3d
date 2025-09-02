/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:23:32 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/20 15:52:18 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

struct						s_convert
{
	char					*sym;
	int						(*f)(va_list);
};
typedef struct s_convert	t_convert;

typedef struct s_gvar
{
	int						string;
	int						function;
	int						i;
	int						end_value;
	int						chartotal;
	unsigned long long		remainder;
	unsigned long long		lint;
	int						b;
	unsigned int			uni;
	const char				*a;
	char					*hex;
	char					*result;
	void					*ptr;
}							t_variables;

char						*ft_strchr_gnl(const char *s, int c);
size_t						ft_strlen_gnl(const char *s);
int							ft_printf(const char *format, ...);
int							character_count(const char *format, va_list arg,
								t_convert f_list[]);
int							print_string(va_list arg);
int							print_char(va_list arg);
int							print_int(va_list arg);
int							print_unsigned(va_list arg);
int							print_low_hex(va_list arg);
int							print_upp_hex(va_list arg);
int							print_pointer(va_list arg);
char						*reverse_string(char *hex, int len);
int							make_hex(int remainder, unsigned long long lint,
								char *hex, const char *a);
char						*ft_utoa(unsigned int num);
int							ft_isalnum(int c);
int							ft_isalpha(int c);
int							ft_isascii(int c);
int							ft_isdigit(int c);
int							ft_isprint(int c);
int							ft_tolower(int c);
int							ft_toupper(int c);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
void						*ft_memset(void *s, int c, size_t n);
size_t						ft_strlen(const char *s);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
size_t						ft_strlcpy(char *dest, const char *src,
								size_t size);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
char						*ft_strnstr(const char *big, const char *little,
								size_t len);
int							ft_atoi(const char *nptr);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
char						*ft_strdup(const char *s);
void						*ft_calloc(size_t nmemb, size_t size);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s1, char const *set);
char						*ft_strcpy(char *dest, const char *src);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));
void						ft_striteri(char *s, void (*f)(unsigned int,
									char *));
size_t						ft_strlcat(char *dst, const char *src, size_t size);
void						ft_putendl_fd(char *s, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putchar_fd(char c, int fd);
void						ft_putnbr_fd(int n, int fd);
char						*ft_substr(char const *s, unsigned int start,
								size_t len);
char						**ft_split(char const *s, char c);
char						*ft_strjoin_gnl(char *left_str, char *buff);
char						*get_next_line(int fd);

#endif
