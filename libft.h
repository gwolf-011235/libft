/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:55:23 by gwolf             #+#    #+#             */
/*   Updated: 2022/12/02 09:02:43 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>

/* colors */
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define NOC "\033[0m"

/* buffer size for get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# elif BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be bigger than 0"
# endif

/* list for get_next_line */
typedef struct s_buf_node {
	char				buf[BUFFER_SIZE];
	size_t				size;
	bool				has_nl;
	struct s_buf_node	*next;
	struct s_buf_node	*tail;
}				t_buf_node;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/* libft standard */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char const *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* get_next_line */
char		*get_next_line(int fd);
bool		ft_read_into_buf(int fd, t_buf_node **head, size_t *p_line_size);
bool		ft_search_nl(t_buf_node **head, int rd_bts);
bool		ft_save_the_buf(char *temp, int rd_bts, t_buf_node *cur_node);
char		*ft_prep_line(t_buf_node **head, size_t	*p_line_size);

/* get_next_line_utils */
char		*ft_lstclear_plus(t_buf_node **head, bool fclear);
t_buf_node	*ft_lstadd_buf(t_buf_node **head);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
