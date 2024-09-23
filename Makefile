# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 15:38:59 by mayyildi          #+#    #+#              #
#    Updated: 2022/11/03 19:26:51 by mayyildi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	$(wildcard *.c)			\
			$(wildcard utils/*.c)	\
			$(wildcard map/*.c)		\
			$(wildcard gnl/*.c)		\
			$(wildcard minilib/*.c)	\

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

MLX		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

${NAME}:	${OBJS}
			make -C mlx
			${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}
clean:
			${RM} ${OBJS}
			make clean -C mlx

fclean:		clean
			${RM} ${NAME}

re:			fclean all

norm:
			norminette $(SRCS) gnl/*.h minilib/*.h *.h

.PHONY:		all clean fclean re
