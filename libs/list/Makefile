NAME = libint_list.a

SRC = ft_int_lstclear.c			\
	  ft_int_lstdelone.c		\
	  ft_int_lstnew.c			\
	  ft_int_lstadd_back.c		\
	  ft_int_lstadd_front.c		\

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ../../include

CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
AR = ar

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
