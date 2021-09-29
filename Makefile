# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takuya <takuya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 23:16:26 by takuya            #+#    #+#              #
#    Updated: 2021/04/08 17:48:36 by takuya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS =  ./src/checker.c\
# 		./src/manipulate_list.c\
# 		./src/operations.c\
# 		./src/get_next_line.c\

SRCS =  ./src/checker.c\
		./src/manipulate_list.c\
		./src/operations.c\
		./src/get_next_line.c\
		./src/sort_algo.c\
		./src/push_swap.c\
		./src/sort_algo_utils.c\
		./src/threenum_sort.c\
		./src/threenum_sort2.c\
		./src/test_sort_algo.c\
		./src/operations_util.c\
		./src/mergesort.c\

OBJS    = $(SRCS:.c=.o)
# NAME    = checker
NAME    = push_swap
CC      = gcc -g
# CC      = gcc -Wall -Wextra -Werror
RM      = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	# $(RM) $(NAME) checker.a
	$(RM) $(NAME) push_swap.a

re: fclean all

.PHONY: all clean fclean re .c.o