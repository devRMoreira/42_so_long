/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:00:47 by rimagalh          #+#    #+#             */
/*   Updated: 2024/12/10 15:54:41 by rimagalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
//getnextline
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

//libft
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//printf
# include <stdarg.h>

//getnextline
# include <fcntl.h>

//og libft
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

//printf
void	ft_putnbr_base(long nbr, char *base);
void	ft_putnbr_unsigned_base(unsigned long nbr, char *base);
int		ft_input_convert(int type, va_list args);
int		ft_input_handler(const char *input, va_list args);
int		ft_input_type(char c);
int		ft_output_long(int type, va_list args);
int		ft_output_single(int type, va_list args);
int		ft_printf(const char *input, ...);
int		ft_putnbr(long n, char *base);
int		ft_putnbr_unsigned(unsigned long n, char *base);
int		ft_putptr(void *ptr);
int		ft_putstr(char *str);

//getnextline
char	*ft_get_next_line(int fd);

#endif
