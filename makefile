SRCS		= server.c client.c libft/*.c

OBJS		= *.o

NAME		= minitalk.a

CC			= gcc

RM			= rm -rf

CFLAGS		= -Wall -Werror -Wextra

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -c ${SRCS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
		
re:			fclean all

.PHONY:		all clean fclean re