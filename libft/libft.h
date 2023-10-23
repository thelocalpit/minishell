/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/12 16:31:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <strings.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_isalpha(int x);
int		ft_isascii(int x);
int		ft_isprint(int x);
int		ft_isdigit(int x);
int		ft_isalnum(int x);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int x);
int		ft_tolower(int x);
int		ft_printcore(char spec, va_list arguments);
int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstring(char *str);
int		ft_printhexa(unsigned int to_hex, char s);
int		ft_printnum(long num);
int		ft_printpointer(unsigned long point);
int		ft_printundec(unsigned int decimal);
char	ft_chck(char to_check);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split_set(char *s, char *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

char	*get_next_line(int fd, bool is_file);
char	*readnsave(int fd, char *str);
char	*save_rest(char *str);
char	*ft_gline(char *str);
size_t	ft_cstrlen(char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*str_join_mod(char *str1, char *str2);
char	*ft_strchr_mod(char *str, int c);

#endif
