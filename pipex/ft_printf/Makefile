NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

EXISTING_LIB_DIR = ../libft
EXISTING_LIB = $(EXISTING_LIB_DIR)/libft.a
SRC_DIR = srcs

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(EXISTING_LIB)
	cp $(EXISTING_LIB) $(NAME)
	ar -rcs $@ $(OBJS)

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
