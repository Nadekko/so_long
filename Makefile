CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Ofast

NAME = so_long

INC = include/so_long.h
MLX_INC = -I./minilibx-linux -Iinclude

MLX_DIR = minilibx-linux
MLX_EXEC = ./minilibx-linux/libmlx.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

LIBFT = ./libft/libft.a
LIBPRINTF = ./libft/ft_printf/libftprintf.a

SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "SO_LONG COMPILED!"

$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF) $(MLX_EXEC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBPRINTF) $(MLX_FLAGS)

$(LIBFT):
	make -sC libft

$(LIBPRINTF):
	make -sC libft/ft_printf

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(MLX_EXEC): $(MLX_DIR)
	make -s -C $(MLX_DIR)

%.o: %.c $(INC) $(MLX_EXEC)
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(MLX_DIR) 
	make -sC libft clean
	make -sC libft/ft_printf clean
	@if [ -d "$(MLX_DIR)" ]; then make -sC $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	make -sC libft fclean
	make -sC libft/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re