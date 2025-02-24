/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:07:02 by micha             #+#    #+#             */
/*   Updated: 2024/10/01 12:25:55 by micha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long			ft_atoi(const char *str);
void			ft_bzero(void *dest, size_t n);
int				ft_isalnum(int ch);
int				ft_isalpha(int ch);
int				ft_isascii(int ch);
int				ft_isdigit(int ch);
int				ft_isprint(int ch);
void			*ft_memchr(const void *ptr, int ch, size_t count);
int				ft_memcmp(const void *str1, const void *str2, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t count);
void			*ft_memset(void *dest, int ch, size_t count);
char			*ft_strchr(const char *str, int ch);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t count);
char			*ft_strnstr(const char *str, const char *find, size_t len);
char			*ft_strrchr(const char *str, int ch);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
void			*ft_calloc(size_t nitems, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strdup(const char *src);
void			*ft_memmove(void *dest, void *src, size_t count);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
int				ft_atoi_base(char *str, char *base);

#endif
