NAME = pipex

LIB = libft/libft.a

SRCDIR = ./
OBJDIR = obj/

FLAGS = -Wall -Wextra -Werror

SRC		=	${SRCDIR}pipex.c			\
			${SRCDIR}ft_pipex_utils.c	\

OBJ	= $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

all:${NAME}

${LIB}:
	@cd libft && make bonus

${OBJDIR}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c | ${OBJDIR}
	@cc ${FLAGS} -c $< -o $@

${NAME}: ${LIB} ${OBJDIR} ${OBJ}
	@cc ${FLAGS} -o ${NAME} ${OBJ} ${LIB}

bonus:

clean:
	@rm -rf ${OBJDIR}
	@cd libft && make clean

fclean:clean
	@rm -rf ${NAME}
	@cd libft && make fclean

re: fclean all

PHONY: all bonus clean fclean re