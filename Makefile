DEF_COLOR = \033[0;39m
RED = \033[0;91m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -Ofast

INC = include/so_long.h

MLX_INC = -I/usr/include -Imlx_linux

MLX_FLAGS = -Lmlx_linux -L/usr/lib -lXext -lX11 -lm

MLX = ./minilibx/libmlx.a

LIBFT = ./libft/libft.a
LIBPRINTF = ./libft/ft_printf/libftprintf.a

SRCS = $(wildcard srcs/*.c)

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME) $(MLX) $(LIBFT) $(LIBPRINTF)
	@echo "$(CYAN)SO_LONG COMPILED!$(DEF_COLOR)"


$(LIBFT):
	@make -sC libft

$(MLX):
	@make -sC minilibx > /dev/null 2>&1
	@echo "$(PURPLE)MINILIBX COMPILED!$(DEF_COLOR)"

$(NAME): $(OBJS) $(LIBFT) $(LIBPRINTF) $(MLX)
	@$(CC) $(CFLAGS) $(MLX_INC) -o $(NAME) $(OBJS) $(LIBFT) $(LIBPRINTF) $(MLX_FLAGS) $(MLX)

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C libft clean > /dev/null 2>&1
	@make -C libft/ft_printf clean > /dev/null 2>&1
	@make -C minilibx clean > /dev/null 2>&1
	@echo "$(YELLOW)CLEANED!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean > /dev/null 2>&1
	@make -C libft/ft_printf fclean > /dev/null 2>&1
	@echo "$(RED)FCLEANED!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re