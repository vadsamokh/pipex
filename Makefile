.PHONY:	re all clean fclean

NAME =	pipex

SRCS =	./srcs/main.c \
		./srcs/utils.c \
		./srcs/errors.c

INCLUDES =	./headers

LIBRARIES =	./libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${LIBRARIES}:
		make -C ./libft/
		cp ./libft/libft.a .

${NAME}: ${SRCS} ${INCLUDES} ${LIBRARIES}
		${CC} ${SRCS} -o ${NAME} ${CFLAGS} -I ${INCLUDES} ${LIBRARIES}

clean:
		$(MAKE) clean -C ./libft/


fclean:	clean
		$(MAKE) fclean -C ./libft/
		rm -f ${LIBRARIES}
		rm -f ${NAME}

re:		fclean all
