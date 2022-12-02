NAME := libft.a

SRC :=	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c

SRC_B := 	ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\
			ft_lstiter.c\
			ft_lstmap.c

OBJ := $(SRC:.c=.o)

OBJ_B := $(SRC_B:.c=.o)

CFLAGS = -Wall -Werror -Wextra

.PHONY: all, bonus, clean, fclean, re, re_bonus

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) -c $(SRC)

bonus: $(OBJ) $(OBJ_B)
	@ar -rcs $(NAME) $(OBJ) $(OBJ_B)

clean:
	@rm -f *.o

fclean:
	@rm *.o -f
	@rm $(NAME) -f

re: fclean all

re_bonus: fclean bonus clean
