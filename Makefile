NAME= minishell
LIBFT_DIR= libft
LIBFT_NAME= $(addprefix $(LIBFT_DIR)/,libft.a)
SRC= main.c pwd.c
OBJ= $(SRC:.c=.o)
FLAGS= -Wall -Wextra -Werror
RFLAGS= -lreadline
RM= rm -rf
CC= gcc

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ) $(LIBFT_NAME)
	@echo "Linking $(NAME)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_NAME) -o $@ $(RFLAGS)

%.o: %.c
	@echo "Compiling source files"
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_NAME):
	@echo "Building libft"
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "Cleaning up object files"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@echo "Removing $(NAME) and libft"
	@$(RM) $(LIBFT_NAME)
	@$(RM) $(NAME) $(OBJ)

re: fclean
	@$(MAKE)

.PHONY: all re clean fclean make
.SILENT: all