SRCS=stack.c instructions.c instructions_2.c utils.c utils_2.c utils_3.c valid_input.c \
lis.c find_lis.c prepare_stack.c sort.c rotate.c  sort_utils.c\
check_args.c check_args_utils.c libft_utils.c checker_utils.c
CHECKER_SRCS=checker.c  get_next_line.c get_next_line_utils.c \
instructions.c instructions_2.c utils.c utils_2.c utils_3.c valid_input.c \
lis.c find_lis.c prepare_stack.c sort.c rotate.c  sort_utils.c\
check_args.c check_args_utils.c libft_utils.c checker_utils.c
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
	$(CC)  $(CFLAGS) $(CHECKER_OBJS)  -o checker 
fclean: clean
	rm -rf $(NAME) checker
clean:
	rm -rf $(OBJS) $(CHECKER_OBJS)
re:fclean all
