SERVER		= server.c

CLIENT		= client.c

LIBFT		= libft/libft.a

CC			= gcc

RM			= rm -rf 

CFLAGS		= -Wall -Werror -Wextra 

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -c ${SRCS}
			ar rcs ${NAME} ${OBJS}

server:		
			make -C libft
			${CC} ${CFLAGS} -c ${SRCS}
			ar rcs ${}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
		
re:			fclean all

.PHONY:		all clean fclean re