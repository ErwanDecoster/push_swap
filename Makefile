# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edecoste <edecoste@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:51:30 by edecoste          #+#    #+#              #
#    Updated: 2023/01/18 16:11:48 by edecoste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap_move_0.c \
				push_swap_move_1.c \
				push_swap_move_2.c \
				push_swap_tools.c \
				push_swap.c \
				close.c \
				stack.c \

HEADERS		= push_swap.h

OBJS		= ${SRCS:.c=.o}

FLAGS		= -Wall -Wextra -Werror

NAME		= push_swap

CC			= cc

RM			= rm -f

%.o: 		%.c ${HEADERS}	Makefile
			${CC} ${FLAGS} -c $< -o $@ -I ${HEADERS}

${NAME}:	makelib ${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS} Libft/libft.a

all:		${NAME}

makelib:
			make bonus -C ./Libft/

clean:
			${RM} ${OBJS}
			make clean -C ./Libft/
			
fclean:		clean
			${RM} ${NAME}
			make fclean -C ./Libft/

re:			fclean all

.PHONY: 	all clean fclean re makelib