NAME = pipex
BONUS = pipex_bonus

LIB = libft/libft.a

SRCDIR = ./
OBJDIR = obj/

FLAGS = -Wall -Wextra -Werror -g

SRC		=	${SRCDIR}pipex.c				\
			${SRCDIR}ft_pipex_commands.c	\
			${SRCDIR}ft_pipex_paths.c		\
			${SRCDIR}ft_pipex_sleep.c		\
			${SRCDIR}ft_pipex_utils.c		\

BSRC	=	${SRCDIR}pipex_bonus.c			\
			${SRCDIR}ft_pipex_commands.c	\
			${SRCDIR}ft_pipex_paths.c		\
			${SRCDIR}ft_pipex_sleep.c		\
			${SRCDIR}ft_pipex_utils.c		\

OBJ	= $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
BOBJ = $(BSRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

all:${NAME}

${LIB}:
	@cd libft && make bonus

${OBJDIR}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c | ${OBJDIR}
	@cc ${FLAGS} -c $< -o $@
	@echo "\e[0;34m -$@ created."

${NAME}: ${LIB} ${OBJ}
	@cc ${FLAGS} -o ${NAME} ${OBJ} ${LIB}
	@echo "\e[0;32m $@ linked.\n"

bonus: ${BONUS}

${BONUS}: ${LIB} ${BOBJ}
	@cc ${FLAGS} -o ${BONUS} ${BOBJ} ${LIB}
	@echo "\e[0;32m Bonus $(NAME) linked.\n"

clean:
	@rm -rf ${OBJDIR}
	@cd libft && make clean

fclean:clean
	@rm -rf ${NAME}
	@rm -rf ${BONUS}
	@cd libft && make fclean

re: fclean all

PHONY: all bonus clean fclean re