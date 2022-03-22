SRCS=stack.c instructions.c instructions_2.c utils.c utils_2.c utils_3.c valid_input.c \
lis.c find_lis.c prepare_stack.c sort.c rotate.c  sort_utils.c\
check_args.c check_args_utils.c libft_utils.c checker_utils.c  testing.c 
CHECKER_SRCS=checker.c  get_next_line.c get_next_line_utils.c \
utils.c utils_2.c utils_3.c instructions.c valid_input.c \
lis.c find_lis.c prepare_stack.c sort.c rotate.c  sort_utils.c instructions_2.c\
check_args.c check_args_utils.c libft_utils.c checker_utils.c testing.c err_handl.c leak_check.c
OBJS=$(SRCS:.c=.o)
CHECKER_OBJS=$(CHECKER_SRCS:.c=.o)
NAME=push_swap
CFLAGS= -Wall -Wextra -Werror 
CC=gcc

$(NAME):$(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< 
all:$(NAME)

bonus:$(NAME) checker

checker:$(CHECKER_OBJS) get_next_line.h
	$(CC)  $(CFLAGS) $(CHECKER_OBJS) -ldl -o checker 
fclean: clean
	rm -rf $(NAME) checker
clean:
	rm -rf $(OBJS) $(CHECKER_OBJS)
re:fclean all
