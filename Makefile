# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 10:19:46 by gwolf             #+#    #+#              #
#    Updated: 2023/12/27 13:06:53 by gwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General
NAME := libft.a
CC := cc
CPPFLAGS = -I include/
CFLAGS = -Werror -Wextra -Wall
COMPILE := $(CC) $(CPPFLAGS) $(CFLAGS)

# Colors
RESET := \033[0m
GREEN := \033[32m
RED := \033[31m

# Directories
SRC_PATH := src
OBJ_PATH := obj

SRC_CHAR :=	ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_isspace.c

SRC_FD :=	ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			get_next_line.c\
			get_next_line_utils.c

SRC_LST :=	ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c\
			ft_lstiter.c\
			ft_lstmap.c

SRC_MEM :=	ft_bzero.c\
			ft_calloc.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c

SRC_NUM :=	ft_atoi.c\
			ft_itoa.c\
			ft_itoa_in_place.c

SRC_PRINT :=	ft_printf.c\
	  			ft_printf_utils.c\
	  			ft_put.c\
	  			ft_conversion_c.c\
	  			ft_conversion_i_d.c\
	  			ft_conversion_p.c\
	  			ft_conversion_percent.c\
	  			ft_conversion_s.c\
	  			ft_conversion_u.c\
	  			ft_conversion_x.c\
	  			ft_conversion_X.c

SRC_STR :=	ft_split.c\
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
			ft_strrev.c

SRCS_NAME :=	$(addprefix ft_char/, $(SRC_CHAR))\
				$(addprefix ft_fd/, $(SRC_FD))\
				$(addprefix ft_lst/, $(SRC_LST))\
				$(addprefix ft_mem/, $(SRC_MEM))\
				$(addprefix ft_num/, $(SRC_NUM))\
				$(addprefix ft_print/, $(SRC_PRINT))\
				$(addprefix ft_str/, $(SRC_STR))

OBJS_NAME := $(SRCS_NAME:.c=.o)
OBJ_DIRS :=	ft_char\
			ft_fd\
			ft_lst\
			ft_mem\
			ft_num\
			ft_print\
			ft_str

SRCS := $(addprefix $(SRC_PATH)/, $(SRCS_NAME))
OBJS := $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

.PHONY: all
all: $(NAME)
	@printf "$(GREEN)%-50s$(RESET)\n" "$(NAME) done"

$(NAME): $(OBJS)
	@printf "\033[2K\r$(GREEN)%-50s$(RESET)\n" "Compilation done"
	ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(addprefix $(OBJ_PATH)/, $(OBJ_DIRS))

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(COMPILE) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(OBJ_PATH)
	@printf "$(RED)subdir $(OBJ_PATH) removed$(RESET)\n"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(NAME) removed$(RESET)\n"

.PHONY: re
re: fclean all
