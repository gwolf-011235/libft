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

SRC_G :=	get_next_line.c\
			get_next_line_utils.c

OBJ := $(SRC:.c=.o)

OBJ_B := $(SRC_B:.c=.o)

OBJ_G := $(SRC_G:.c=.o)

CFLAGS = -Werror -Wextra -Wall -g

CC := cc

.PHONY: all, bonus, clean, fclean, re, re_bonus

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_B) $(OBJ_G)
	@echo "** libft **"
	@echo "Creating archive"
	@ar -rcs $(NAME) $(OBJ) $(OBJ_B) $(OBJ_G)

$(OBJ): $(SRC)
	@echo "** libft **"
	@echo "Creating o. files"
	@$(CC) -c $(SRC)

$(OBJ_B): $(SRC_B)
	@$(CC) -c $(SRC_B)

$(OBJ_G): $(SRC_G)
	@$(CC) -c $(SRC_G)

initial: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	@ar -rcs $(NAME) $(OBJ) $(OBJ_B)

clean:
	@echo "** libft **"
	@echo "Deleting o. files"
	@rm -f *.o

fclean:
	@echo "** libft **"
	@echo "Deleting o. files and archive libft.a"
	@rm *.o -f
	@rm $(NAME) -f

re: fclean all

re_bonus: fclean bonus clean
