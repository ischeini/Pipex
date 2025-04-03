NAME = pipex

LIB = libft/libft.a

SRCDIR = ./
OBJDIR = ./OBJ

FLAGS = -Wall -Wextra -Werror

SRC		=	${SRCDIR}pipex.c	\

OBJ		=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

${NAME}: ${OBJDIR} ${OBJ}
	@cc ${FLAGS} ${OBJ} -o ${NAME}

${OBJDIR}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@cc ${FLAGS} ${LIB} -c $< -o $@

all:${NAME}

bonus:

clean:
	@rm -rf ${OBJDIR}
	@cd libft && make clean

fclean:clean
	@rm -rf ${NAME}
	@cd libft && make fclean

re: fclean all

PHONY: all bonus clean fclean re