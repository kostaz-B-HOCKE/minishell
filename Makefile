NAME		= minishell

SRB_DIR		= src/

SRB		= $(addprefix $(SRB_DIR), main.c execve_unil.c pipex.c init.c \
					adoption_cmd.c)
#SRB		= $(addprefix $(SRB_DIR), main.c)

OBJ			= $(SRB:.c=.o)

LIB			= libft/libft.a

#CFLAGS		= -Wall -Wextra -Werror
CFLAGS		=

all:		$(LIB) $(NAME)

RED			=	"\033[1;31m"
BLUE		=	"\033[1;34m"
YELLOW		=	"\033[1;33m"
WHITE		=	"\033[1;37m"
GREEN		=	"\033[1;32m"
PURPLE		=	"\033[1;35m"
GRAY		=	"\033[1;30m"
END			=	"\033[0m"
#@echo ${YELLOW} "\n< .o files -> removed >\n" ${END}

.PHONY:		all clean fclean re

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) -L /Users/$(USER)/.brew/opt/readline/lib/ -lreadline -L libft -lft -o ${NAME} ${OBJ}

$(LIB):
			@make -C libft

clean:
			@$(RM) $(OBJ)
			@make $@ -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make $@ -C libft

re:			fclean all
