SRCS=stack.c instructions.c instructions_2.c utils.c utils_2.c utils_3.c valid_input.c \
lis.c find_lis.c prepare_stack.c sort.c rotate.c move_non_lis.c \
testing.c
OBJS=$(SRCS:.c=.o)
NAME=push_swap
CFLAGS= -Wall -Wextra -Werror
CC=gcc

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< 
all:$(NAME) checker

checker:
	$(CC)  $(CFLAGS) checker.c -o checker
fclean: clean
	rm -rf $(NAME) checker
clean:
	rm -rf *.o
re:fclean all
