NAME := push_swap

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC := main.c

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

IFLAGS := -I$(LIBFT_DIR)
CFLAGS := -Wall -Werror -Wextra -g
LFLAGS := -fsanitize=address -L$(LIBFT_DIR) -lft

CC := clang

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

run: $(NAME)
	./$(NAME) 2 1 3 6 5 8 2147483647 -2147483648; sleep 3



$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p ./obj

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
