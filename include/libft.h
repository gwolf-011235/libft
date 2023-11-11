/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:34:01 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/11 10:15:01 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ====== LIBRARIES ====== */

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

/* ===== DEFINES ===== */

/* buffer size for get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# elif BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be bigger than 0"
# endif

/* cluster size for how many fd*/
# ifndef CLUSTER_SIZE
#  define CLUSTER_SIZE 1
# elif CLUSTER_SIZE <= 0
#  error "CLUSTER_SIZE must be bigger than 0"
# endif

/* ====== TYPEDEFS ====== */

/* generic list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/* list for get_next_line */
typedef struct s_buf_node {
	char				buf[BUFFER_SIZE];
	size_t				size;
	bool				has_nl;
	struct s_buf_node	*next;
	struct s_buf_node	*tail;
}				t_buf_node;

/* struct for ft_printf */
typedef struct s_label {
	va_list	args;
	bool	hash;
	bool	plus;
	bool	space;
	bool	minus;
	bool	zero;
	int		width;
	int		precision;
	int		len;
	bool	neg;
	bool	empty;
	size_t	count;
}	t_label;

/* function ptr for ft_printf */
typedef void	(*t_ftptr)(t_label *, bool fastprint);

/* ====== FUNCTIONS ====== */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char const *s, void (*f)(unsigned int, char*));

void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* get_next_line */
char		*get_next_line(int fd);

/* get_next_line_utils */
char		*ft_lstclear_plus(t_buf_node **head, bool fclear);
char		*ft_clear_all_buffers(t_buf_node *cluster[CLUSTER_SIZE]);
t_buf_node	*ft_lstadd_buf(t_buf_node **head);

/* ft_printf */
int			ft_printf(const char *format, ...) \
				__attribute__ ((format (printf, 1, 2)));
bool		ft_check_string(t_label *label, const char *format);
bool		ft_check_conv(t_label *label, unsigned char c);
int			ft_check_flags(t_label *label, char c);
t_ftptr		ft_look_up_ptr(unsigned char c);

/* ft_printf_utils */
void		ft_init_label(t_label *label);
int			ft_check_sign_pos(t_label *label, char c);
int			ft_count_digits(long num, int base, unsigned long num2);
int			ft_check_padding(t_label *label);
int			ft_check_sign(t_label *label);

/* ft_put */
void		ft_putchar(unsigned char c, size_t *count);
void		ft_putstr(const char *s, size_t *count, int strlen);
void		ft_putnbr(long nbr, size_t *count);
void		ft_puthex(unsigned long nbr, size_t *count, char c);
void		ft_putptr(unsigned long nbr, size_t *count);

/* ft_conversion_c */
void		ft_convert_c(t_label *label, bool fastprint);
void		ft_print_c(t_label *label, unsigned char c);

/* ft_conversion_s */
void		ft_convert_s(t_label *label, bool fastprint);
int			ft_flags_s(t_label *label, const char *s);
void		ft_print_s(t_label *label, const char *s, int strlen);

/* ft_conversion_p */
void		ft_convert_p(t_label *label, bool fastprint);
void		ft_print_p(t_label *label, unsigned long num);

/* ft_conversion_i_d */
void		ft_convert_i(t_label *label, bool fastprint);
void		ft_flags_i(t_label *label, int num);
void		ft_print_i(t_label *label, int num, size_t *count);

/* ft_conversion_u */
void		ft_convert_u(t_label *label, bool fastprint);
void		ft_flags_u(t_label *label, unsigned int num);
void		ft_print_u(t_label *label, unsigned int num, size_t *count);

/* ft_conversion_x */
void		ft_convert_x(t_label *label, bool fastprint);
void		ft_flags_x(t_label *label, unsigned int num);
void		ft_print_x(t_label *label, unsigned int num, size_t *count);

/* ft_conversion_X */
void		ft_convert_x_big(t_label *label, bool fastprint);
void		ft_flags_x_big(t_label *label, unsigned int num);
void		ft_print_x_big(t_label *label, unsigned int num, size_t *count);

/* ft_conversion_percent */
void		ft_convert_percent(t_label *label, bool fastprint);

#endif