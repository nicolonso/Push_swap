NAME  = push_swap.h

SRCS = 	../src/push_swap/split.c \
		../src/push_swap/stack_init.c \
		../src/push_swap/push_swap.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)