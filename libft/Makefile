SRCS_DIR = ./srcs
OBJS_DIR = ./objs
INCLUDE_DIR = ./include

SRCS_FILES = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
			ft_atoi.c ft_atol.c \
			ft_isspace.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strtoupper.c \
			ft_calloc.c ft_strdup.c ft_ends_with.c ft_min.c ft_max.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_itox.c ft_stox.c ft_uitoa.c ft_stoa_base.c\
			ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ft_memjoin.c ft_isnumber.c \
			get_next_line.c \
			ft_stack_new.c ft_stack_do_nothing.c ft_stack_pop.c \
			ft_stack_push.c ft_stack_destroy.c

SRCS = ${addprefix ${SRCS_DIR}/, ${SRCS_FILES}}

OBJS_FILES = ${SRCS_FILES:.c=.o}

OBJS = ${addprefix ${OBJS_DIR}/, ${OBJS_FILES}}

NAME = libft.a

CFLAGS = -g -Wall -Werror -Wextra -I$(INCLUDE_DIR)
LIBFLAGS = rcs

CC = gcc ${CFLAGS}
MAKELIB = ar ${LIBFLAGS}

all: ${NAME}

${NAME}: ${OBJS}
	${MAKELIB} ${NAME} $?

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${OBJS_DIR}
	${CC} -c $< -o $@

clean:
	@echo cleaning libft...
	@rm -f ${OBJS}
	@echo done!

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: fclean clean re test all
