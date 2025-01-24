CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

SRCS = refresh_a_nodes.c  sort.c  stack_utils.c  do_move_helper.c push.c  refresh_b_nodes.c \
       split_args.c swap.c is_valid.c reverse_rotate.c split.c rotate.c split_utils.c main.c

BONUS_SRCS = bonus/checker.c bonus/utils_1.c bonus/utils_2.c stack_utils.c split.c split_args.c \
		split_utils.c is_valid.c push.c swap.c rotate.c reverse_rotate.c \
		bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) 
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re
