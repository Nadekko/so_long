DEF_COLOR = \033[0;39m
RED       = \033[0;91m
YELLOW    = \033[0;93m
GREEN     = \033[0;92m
BLUE      = \033[0;94m
CYAN      = \033[0;96m

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

SRCS = \
	ft_isalnum.c \
	ft_isprint.c \
	ft_memcmp.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strlcat.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_split.c \
	ft_strchr.c \
	ft_strlcpy.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_itoa.c \
	ft_atol.c \
	ft_strnstr.c \
	ft_tolower.c \
	ft_bzero.c \
	ft_isascii.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strrchr.c \
	ft_striteri.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_isdigit.c \
	ft_memchr.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_aff.c \
	ft_printf/ft_printf_nbr.c \
	ft_printf/ft_printf_utils.c \
	ft_printf/ft_printf_unsign.c

BSRCS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line/get_next_line_bonus.c \
	get_next_line/get_next_line_utils_bonus.c

OBJS  = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Creating $(NAME)...$(DEF_COLOR)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)LIBFT COMPILED!$(DEF_COLOR)"

bonus: $(OBJS) $(BOBJS)
	@echo "$(CYAN)Adding bonus objects to $(NAME)...$(DEF_COLOR)"
	@ar rc $(NAME) $(OBJS) $(BOBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)LIBFT BONUS COMPILED!$(DEF_COLOR)"

%.o: %.c
	@echo "$(BLUE)Compiling $<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning libft objects...$(DEF_COLOR)"
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(DEF_COLOR)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus