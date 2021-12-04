NAME := push_swap

CHECKER := checker

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

LIB_STACK_DIR = ./libs/stack
LIB_LIST_DIR = ./libs/list

LIB_STACK = $(LIB_STACK_DIR)/libstack.a
LIB_LIST = $(LIB_LIST_DIR)/libint_list.a

SRC := main.c								\
	   solver.c								\
	   solver_utils.c						\
	   solver_three.c						\
	   solver_three_ascending.c				\
	   solver_three_descending.c			\
	   validation.c							\
	   validation_utils.c					\
	   error.c								\
	   statements_handler.c					\
	   statements_runner.c					\
	   quick_sort.c							\
	   optmizer.c							\
	   output.c								\

CHECKER_SRC := checker_bonus.c				\
			   output_bonus.c 				\
	   		   utils_bonus.c				\
			   validation.c					\
			   validation_utils.c			\
	   		   statements_handler.c			\
			   error.c						\

HEADERS := ./include/push_swap.h

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CHECKER_OBJ := $(addprefix $(OBJ_DIR)/, $(CHECKER_SRC:.c=.o))

IFLAGS := -I./include
CFLAGS := -Wall -Werror -Wextra -g3
LFLAGS := -L$(LIBFT_DIR) -lft 				\
		  -L$(LIB_STACK_DIR) -lstack 		\
		  -L$(LIB_LIST_DIR) -lint_list 		\

CC := gcc
VALGRIND := valgrind --leak-check=full --show-leak-kinds=all

all: $(NAME)

$(NAME): $(LIB_STACK) $(LIB_LIST) $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

$(CHECKER): $(LIB_STACK) $(LIB_LIST) $(LIBFT) $(OBJ_DIR) $(CHECKER_OBJ)
	$(CC) -o $(CHECKER) $(CHECKER_OBJ) $(LFLAGS)

bonus: $(CHECKER)

test: all
	bash test.sh

$(LIBFT):
	make -j6 -C $(LIBFT_DIR)

$(LIB_LIST):
	make -j6 -C $(LIB_LIST_DIR)

$(LIB_STACK):
	make -j6 -C $(LIB_STACK_DIR)

run: $(NAME)
	$(VALGRIND) ./$(NAME) 2 1 3 6 5 8 2147483647 -2147483648; sleep 3

$(OBJ_DIR)/%.o: $(SRC_DIR)/mandatory/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/bonus/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p ./obj

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIB_LIST_DIR) clean
	make -C $(LIB_STACK_DIR) clean
	$(RM) $(OBJ) $(CHECKER_OBJ) vgcore*

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(LIB_LIST_DIR) fclean
	make -C $(LIB_STACK_DIR) fclean
	$(RM) $(NAME)

re:
	make fclean
	make all
