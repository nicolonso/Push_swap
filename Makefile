# Standard
NAME				= push_swap

# Directories
LIBFT				= ./Lib/libft.a
HDR					= hdr/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I$(HDR)
RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)Commands/push.c \
						$(SRC_DIR)Commands/reverse.c \
						$(SRC_DIR)Commands/rotate.c \
						$(SRC_DIR)Commands/swap.c \
						$(SRC_DIR)Commands/sort_three.c \
						$(SRC_DIR)Commands/sort_stacks.c 

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_utilies.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/stack_init_a_to_b.c \
						$(SRC_DIR)push_swap/stack_init_b_to_a.c \

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./Lib

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./Lib

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re