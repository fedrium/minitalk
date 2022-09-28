SERVER		= server

CLIENT		= client

LIBFT		= libft/libft.a

CC			= gcc

RM			= rm -rf 

CFLAGS		= -Wall -Werror -Wextra 

all:		${SERVER} ${CLIENT}

${LIBFT}:	
			make -C ${LIBFT}

${SERVER}:	${LIBFT}
			${CC} ${CFLAGS} ${SERVER}.c ${LIBFT} -o ${SERVER}

${CLIENT}:	${LIBFT}
			${CC} ${CFLAGS} ${CLIENT}.c ${LIBFT} -o ${CLIENT}

clean:
			${RM} *.o

fclean:		clean
			${RM} client server
		
re:			fclean all

.PHONY:		all clean fclean re