/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusimone <gusimone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:03:54 by gusimone          #+#    #+#             */
/*   Updated: 2023/01/02 16:26:39 by gusimone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// GNL
# include <fcntl.h>
# include <unistd.h>
// # include "../libft/libft.h"

void	ft_free_gnl(char *ptr);
char	*get_next_line(int fd);
int		ft_read(int fd, char **buf, char **s_buff, char **line);
char	*ft_get_line(char **line, char **s_buff);

// PRINTF
# include <stdarg.h>
unsigned long long	ft_ull_strlen(char *s);
void				ft_putchar_ret(char c, int *ret);
void				ft_putstr_ret(char *str, int *ret);
void				ft_putnbr_ret(int nb, int *ret);
void				ft_putnbr_u_ret(unsigned int nb, int *ret);
void				ft_address(unsigned long long nb, char *base, int *ret);
int					ft_if_conv(char c);
void				ft_base(int nb, char *base, int *ret);
void				ft_which_one(char c, va_list arg, int *ret);
int					ft_scan_printf(int i, char *str, int ret, va_list arg);
int					ft_printf(const char *str, ...);

// Malloc et free

typedef struct s_free
{
	void			*ptr;
	struct s_free	*next;
}	t_free;

typedef struct s_m_free
{
	struct s_free	*list;
}	t_m_free;

void				*ft_free_malloc(t_m_free *m_free, size_t size);
void				ft_free(t_m_free *m_free);
int				ft_free_size(t_m_free *m_free);
void				ft_free_remove(t_m_free *m_free, void *ptr);
t_m_free			*ft_free_init(void);
int				ft_free_add(t_m_free *m_free, void *ptr);

// PT.1
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *destination, const void *source, size_t size );
void	*ft_memmove(void *destination, const void *source, size_t size );
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t length);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *source);

//PT.2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);;
void	ft_putnbr_fd(int n, int fd);

//PT.BONUS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif
