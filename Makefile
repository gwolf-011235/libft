# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 09:30:37 by gwolf             #+#    #+#              #
#    Updated: 2023/11/11 10:12:33 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS = -Werror -Wextra -Wall -fPIE
BUF_SIZE ?= 4096
BUFFER = -DBUFFER_SIZE=$(BUF_SIZE)
INCLUDE := -I include/
COMPILE := $(CC) $(CFLAGS) $(BUFFER) $(INCLUDE)

#Colors
RESET := \033[0m
GREEN := \033[32m
RED := \033[31m

NAME := libft.a

SRC_PATH := src
OBJ_PATH := obj

SRC :=	ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_printf.c\
	  	ft_printf_utils.c\
	  	ft_put.c\
	  	ft_conversion_c.c\
	  	ft_conversion_i_d.c\
	  	ft_conversion_p.c\
	  	ft_conversion_percent.c\
	  	ft_conversion_s.c\
	  	ft_conversion_u.c\
	  	ft_conversion_x.c\
	  	ft_conversion_X.c\
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
		ft_substr.c

SRCS :=	$(addprefix $(SRC_PATH)/, $(SRC))

OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_PATH)/, $(OBJ))

HIT_TOTAL = $(words $(SRCS))
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
ECHO = printf "\033[2K\r[`expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`%%] %s"

.PHONY: all, clean, fclean, re
.SILENT:

all: $(NAME)
	printf "$(GREEN)%-50s$(RESET)\n" "$(NAME) done"

$(NAME): $(OBJS)
	printf "\033[2K\r$(GREEN)%-50s$(RESET)\n" "Compilation done"
	ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(ECHO) "$(COMPILE) $@"
	$(COMPILE) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
	printf "$(RED)subdir $(OBJ_PATH) cleaned$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	printf "$(RED)$(NAME) cleaned$(RESET)\n"

re: fclean all
