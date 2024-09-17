NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

EXISTING_LIB_DIR = ./libft
EXISTING_LIB = $(EXISTING_LIB_DIR)/libft.a
SRC_DIR = srcs

SRCS = 	srcs/error.c			srcs/get_cmd_args.c\
		srcs/free.c				srcs/get_next_line_utils_bonus.c	srcs/pipex.c\
		srcs/get_next_line_bonus.c			srcs/pipex_utils.c\

BONUS_SRCS = pipex_bonus.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(EXISTING_LIB)
	cp $(EXISTING_LIB) $(NAME)
	$(CC) $(CFLAGS) $(EXISTING_LIB) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(EXISTING_LIB):
	make -C $(EXISTING_LIB_DIR) all

clean:
	rm -f $(OBJS)
	make clean -C $(EXISTING_LIB_DIR)

fclean: clean
	rm -f $(NAME) $(EXISTING_LIB)

re: fclean all

.PHONY: all clean fclean re