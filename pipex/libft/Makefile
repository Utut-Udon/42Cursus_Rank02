NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = \
	ft_lstiter.c		ft_putnbr_fd.c		ft_strlcpy.c \
	ft_atoi.c			ft_strlen.c \
	ft_bzero.c			ft_putstr_fd.c		ft_strmapi.c \
	ft_calloc.c			ft_split.c \
	ft_isalnum.c		ft_strncmp.c 		ft_striteri.c\
	ft_isalpha.c		ft_memccpy.c		ft_strchr.c		\
	ft_isascii.c		ft_memchr.c			ft_strnstr.c \
	ft_isdigit.c		ft_memcmp.c			ft_strrchr.c \
	ft_isprint.c		ft_memcpy.c 		ft_utoa.c\
	ft_itoa.c			ft_strtrim.c		ft_htoa.c\
	ft_memmove.c		ft_strdup.c			ft_substr.c \
	ft_memset.c			ft_tolower.c 		ft_ptoa.c\
	ft_putchar_fd.c		ft_strjoin.c		ft_toupper.c \
	ft_putendl_fd.c		ft_strlcat.c \

BONUS_SRCS = \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
	ft_lstsize.c ft_lstclear.c ft_lstdelone.c \

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

bonus:$(BONUS_OBJS) $(NAME)
	ar -rc $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
