/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vi <vi@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:01:04 by vdunatte          #+#    #+#             */
/*   Updated: 2024/06/01 07:02:23 by vi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);//norm / paco-k
void	ft_bzero(void *s, size_t n);//norm / paco-k
void	*ft_calloc(size_t nmemb, size_t size);//norm / paco-k
int		ft_isalnum(int c);//norm / paco-k
int		ft_isalpha(int c);//norm / paco-k
int		ft_isascii(int c);//norm / paco-k
int		ft_isdigit(int c);//norm / paco-k
int		ft_isprint(int c);//norm / paco-k
char	*ft_itoa(int n);//norm / paco-k
void	*ft_memchr(const void *s, int c, size_t n);//norm / paco-k
int		ft_memcmp(const void *s1, const void *s2, size_t n);//norm / paco-k
void	*ft_memcpy(void *dest, const void *src, size_t n);//norm / paco-k
void	*ft_memmove(void *dest, const void *src, size_t n);//norm / paco-k
void	*ft_memset(void *s, int c, size_t n);//norm / paco-k
void	ft_putchar_fd(char c, int fd);//norm / paco-k
void	ft_putendl_fd(char *s, int fd);//norm / paco-k
void	ft_putnbr_fd(int n, int fd);//norm / paco-k
void	ft_putstr_fd(char *s, int fd);//norm / paco-k
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);//norm / paco-k
char	*ft_strdup(const char *s);//norm / paco-k
void	ft_striteri(char *s, void (*f)(unsigned int, char*));//norm / paco-k
char	*ft_strjoin(char const *s1, char const *s2);//norm / paco-k
size_t	ft_strlcat(char *dst, const char *src, size_t size);//norm / paco-k
size_t	ft_strlcpy(char *dst, const char *src, size_t size);//norm / paco-k
size_t	ft_strlen(const char *s);//norm / paco-k
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));//norm/paco-k
int		ft_strncmp(const char *s1, const char *s2, size_t n);//norm / paco-k
int		ft_strncmp_r(const char *s1, const char *s2, int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);//nor/pacok
char	*ft_strrchr(const char *s, int c);//norm / paco-k
char	*ft_strtrim(char const *s1, char const *set);//norm / paco-k
char	*ft_substr(char const *s, unsigned int start, size_t len);//norm/paco-k
char	**ft_tabdup(char **src_tab, char **des_tab);
size_t	ft_tablen(char **tab);
int		ft_tolower(int c);//norm / paco-k
int		ft_toupper(int c);//norm / paco-k

#endif
