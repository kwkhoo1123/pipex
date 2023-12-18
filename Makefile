# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 18:55:51 by kkah-wen          #+#    #+#              #
#    Updated: 2023/06/04 16:02:16 by kkah-wen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS 	= pipex.c utils.c
OBJS 	= ${SRCS:.c=.o}

SRCS_B	= pipex_bonus.c utils.c utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror 

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${OBJS}
					@echo "Compiling pipex"
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${NAME}
					@echo "Pipex compiled!"


bonus:		${OBJS_B}
					@echo "Compiling pipex (bonus)"
					@make re -C ./libft
					@$(CC) ${OBJS_B} -Llibft -lft -o ${NAME}
					@echo "Pipex (bonus) compiled!"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus