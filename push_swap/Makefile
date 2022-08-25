# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhaga <abouhaga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 23:23:26 by abouhaga          #+#    #+#              #
#    Updated: 2022/07/05 23:23:26 by abouhaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         =     gcc

CFLAGS     =     -Wall -Wextra -Werror
NAME     =    push_swap

CHECKER =    checker

LIBFT    =    libft/libft.a

SRCS     =      push_swap.c    \
            ft_sort_small.c \
            ft_sort_big.c \
            ft_search.c \
            ft_operations.c \
            ft_init_stack.c \
            ft_check.c

OBJS    = $(SRCS:.c=.o)

B_SRCS =    ft_checker/get_next_line.c \
            ft_checker/get_next_line_utils.c \
			ft_checker/ft_bonus_operations.c \
			ft_checker/ft_bonus_utils.c \
            ft_checker/ft_bonus_checker.c \
            ft_check.c \
            
B_OBJS    = $(B_SRCS:.c=.o)
all:    $(NAME)

$(NAME):    $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

bonus: $(CHECKER)

$(CHECKER):   $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(CHECKER) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

.PHONY: all clean fclean re 