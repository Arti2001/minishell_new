# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ydidenko <ydidenko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/05 14:27:35 by ydidenko      #+#    #+#                  #
#    Updated: 2024/10/03 13:53:01 by ydidenko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			=	minishell

LIBFT 			=	libft
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	includes

GREEN=\033[0;32m
NC=\033[0m

SRCS			=	$(SRC_DIR)/main.c $(wildcard $(SRC_DIR)/*/*.c)
OBJS 			=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
VPATH			=	$(dir $(SRCS))

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g -lreadline -fsanitize=address -I$(INC_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
				@echo "$(GREEN)Compiled$(NC)"

$(OBJ_DIR)/%.o:	%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIBFT)
				@$(RM) test
				@echo "$(GREEN)Cleaned$(NC)"

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

test:			all
				$(CC) -I$(INC_DIR) -o test test.c $(NAME)

.PHONY:			clean fclean re all test