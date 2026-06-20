CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g3 -Ofast

NAME    = so_long

SRC     = $(wildcard srcs/*.c)
OBJ     = $(SRC:.c=.o)

HEADER  = include/so_long.h

LIBFT   = libft/libft.a

MLX_DIR = minilibx-linux
MLX     = $(MLX_DIR)/libmlx.a

MLX_INC = -I$(MLX_DIR) -Iinclude
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

GREEN   = \033[0;32m
BLUE    = \033[0;34m
CYAN    = \033[0;36m
YELLOW  = \033[0;33m
PURPLE  = \033[0;35m
RED     = \033[0;31m
NC      = \033[0m

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	@echo "$(PURPLE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS)
	@echo "$(GREEN)$(NAME) compiled successfully.$(NC)"

%.o: %.c $(HEADER)
	@echo "$(BLUE)Compiling $<$(NC)"
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(LIBFT):
	@echo "$(CYAN)Building libft...$(NC)"
	@make --no-print-directory -C libft bonus

$(MLX_DIR):
	@echo "$(YELLOW)Cloning MiniLibX...$(NC)"
	@git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(MLX): $(MLX_DIR)
	@echo "$(CYAN)Building MiniLibX...$(NC)"
	@make -s -C $(MLX_DIR)

clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -f $(OBJ)
	@make --no-print-directory -C libft clean
	@if [ -d "$(MLX_DIR)" ]; then make clean -s -C $(MLX_DIR); fi
	@echo "$(GREEN)Clean done.$(NC)"

fclean: clean
	@echo "$(RED)Removing binaries...$(NC)"
	@rm -f $(NAME)
	@make --no-print-directory -C libft fclean
	@rm -rf $(MLX_DIR)
	@echo "$(GREEN)Full clean done.$(NC)"

re: fclean all

.PHONY: all clean fclean re