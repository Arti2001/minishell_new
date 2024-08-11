
NAME = minishell
LIBFT_DIR = libft
LIBFT_NAME = $(addprefix $(LIBFT_DIR)/, libft.a)
BI_DIR = built_in
SRC = main.c
BI_SRC = cd.c pwd.c

OBJ = $(SRC:.c=.o)
BI_OBJ = $(addprefix $(BI_DIR)/, $(BI_SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror
RFLAGS = -lreadline
RM = rm -rf
CC = gcc

# Targets
all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ) $(BI_OBJ) $(LIBFT_NAME) 
	@echo "Linking $(NAME)"
	@$(CC) $(FLAGS) $(OBJ) $(BI_OBJ) $(LIBFT_NAME) -o $@ $(RFLAGS)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(FLAGS) -c $< -o $@

$(BI_DIR)/%.o: $(BI_DIR)/%.c
	@echo "Compiling $< from $(BI_DIR)"
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT_NAME):
	@echo "Building libft"
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "Cleaning up object files"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(BI_OBJ)

fclean: clean
	@echo "Removing $(NAME) and libft"
	@$(RM) $(LIBFT_NAME)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
.SILENT: all