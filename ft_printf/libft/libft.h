/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:41:26 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/05 16:24:49 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int param);
int		ft_isdigit(int param);
int		ft_isalnum(int param);
int		ft_isascii(int param);
int		ft_isprint(int param);
int		ft_toupper(int param);
int		ft_tolower(int param);
int		ft_isspace(char c);
int		ft_lstsize(t_list *lst);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *str, size_t n);
size_t	ft_strlcat(char *dest, const char *str, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_bzero(void *str, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memcpy(void *dest, const void *str, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *str, size_t n);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

#endif
