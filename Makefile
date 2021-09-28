NAME := push_swap

CHECKER := checker

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC := main.c								\
	   solver.c								\
	   validation.c							\

CHECKER_SRC := checker_bonus.c				\
			   output_bonus.c 				\
			   statements_handler_bonus.c	\
			   validation.c

HEADERS := ./include/push_swap.h

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
CHECKER_OBJ := $(addprefix $(OBJ_DIR)/, $(CHECKER_SRC:.c=.o))

IFLAGS := -I$(LIBFT_DIR) -I./include
CFLAGS := -Wall -Werror -Wextra -g3
LFLAGS := -L$(LIBFT_DIR) -lft

CC := clang

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

$(CHECKER): $(LIBFT) $(OBJ_DIR) $(CHECKER_OBJ)
	$(CC) -o $(CHECKER) $(CHECKER_OBJ) $(LFLAGS)

bonus: $(CHECKER)

$(LIBFT):
	make -C $(LIBFT_DIR)

run: $(NAME)
	./$(NAME) 2 1 3 6 5 8 2147483647 -2147483648; sleep 3

$(OBJ_DIR)/%.o: $(SRC_DIR)/mandatory/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/bonus/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p ./obj

clean:
	$(RM) $(OBJ) $(CHECKER_OBJ) vgcore*

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
