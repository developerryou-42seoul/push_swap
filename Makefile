# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 10:33:16 by sryou             #+#    #+#              #
#    Updated: 2022/07/29 16:51:36 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBFT = Libft
LIBFT_LIB = ft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = main.c \
		data.c \
		error.c \
		pivot.c \
		sort_a.c \
		sort_b.c \
		sort_quick_a.c \
		sort_quick_b.c \
		stack_basic1.c \
		stack_basic2.c \
		stack_operate.c \
		stack.c \
		valid.c \
		optimize.c
		

BONUS = main_bonus.c \
		data_bonus.c \
		error_bonus.c \
		stack_basic1_bonus.c \
		stack_basic2_bonus.c \
		stack_operate_bonus.c \
		stack_bonus.c \
		valid_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(B_OBJS)
	NAME = $(BONUS_NAME)
else
	OBJ_FILES = $(OBJS)
endif

$(NAME) : $(OBJ_FILES)
	make bonus -C $(LIBFT)/
	$(CC) $(CFLAGS) $^ -L./$(LIBFT) -l$(LIBFT_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re bonus

all : $(NAME)
clean :
	make fclean -C $(LIBFT)/
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
re : 
	make fclean
	make all
bonus : 
	make WITH_BONUS=1 all
