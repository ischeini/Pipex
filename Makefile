NAME = pipex
BONUS = pipex_bonus

LIB = libft/libft.a

SRCDIR = ./
OBJDIR = obj/

FLAGS = -Wall -Wextra -Werror

SRC		=	${SRCDIR}pipex.c			\
			${SRCDIR}ft_pipex_utils.c	\

BSRC	=	${SRCDIR}pipex_bonus.c		\
			${SRCDIR}ft_pipex_utils.c	\

OBJ	= $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
BOBJ = $(BSRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

all:${NAME}

${LIB}:
	@cd libft && make bonus

${OBJDIR}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c | ${OBJDIR}
	@cc ${FLAGS} -c $< -o $@

${NAME}: ${LIB} ${OBJ}
	@cc ${FLAGS} -o ${NAME} ${OBJ} ${LIB}

bonus: ${BONUS}

${BONUS}: ${LIB} ${BOBJ}
	@cc ${FLAGS} -o ${BONUS} ${BOBJ} ${LIB}

clean:
	@rm -rf ${OBJDIR}
	@cd libft && make clean

fclean:clean
	@rm -rf ${NAME}
	@rm -rf ${BONUS}
	@cd libft && make fclean

re: fclean all

PHONY: all bonus clean fclean re