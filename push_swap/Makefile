NAME       = push_swap
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
LIBFT_DIR  = libft
LIBFT      = $(LIBFT_DIR)/libft.a

SRCS       = push_swap.c \
             parse.c parse_utils.c \
             stack.c utils.c \
             ops_swap.c ops_push.c ops_rotate.c ops_revrotate.c \
             sort_small.c sort_big_utils.c sort_big.c
OBJS       = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
